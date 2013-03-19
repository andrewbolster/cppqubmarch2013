#include <iostream>
#include "shopping_cart.h"
#include "list.h"
#include "array.h"

using namespace std;

namespace demo {
	ShoppingCart * buildShoppingCart(ShoppingCart::CartType type) {
		if(type == ShoppingCart::STANDARD) {
			return new StandardShoppingCart;
		} else {
			return new BusinessShoppingCart;
		}
	}

	ShoppingCart::ShoppingCart() : itemsList(0) {
	}

	ShoppingCart::~ShoppingCart() {
		delete itemsList;
	}

	void ShoppingCart::add(std::string item) {
		if(itemsList == 0) {
			itemsList = buildList();
		}
		itemsList->add(item);
	}

	void ShoppingCart::listContents() {
		cout << "Current cart contents are: " << endl;
		for(int i=0;i<itemsList->length();i++) {
			cout << "\t" << itemsList->get(i) << endl;
		}
	}

	List<string> * StandardShoppingCart::buildList() {
		return new LinkedList<string>;
	}

	List<string> * BusinessShoppingCart::buildList() {
		return new ArrayList<string>(10);
	}
}