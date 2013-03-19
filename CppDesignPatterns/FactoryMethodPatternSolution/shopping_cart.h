#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include<string>
#include "interface.h"

using std::string;

namespace demo {

	class ShoppingCart {
	public:
		ShoppingCart();
		~ShoppingCart();
		enum CartType {STANDARD, BUSINESS};
		void add(string item);
		void listContents();
	protected:
		virtual List<string> * buildList() = 0;
	private:
		List<string> * itemsList;

	};

	class StandardShoppingCart : public ShoppingCart {
	protected:
		List<string> * buildList();
	};

	class BusinessShoppingCart : public ShoppingCart {
		List<string> * buildList();
	};

	//A factory method for building carts
	ShoppingCart * buildShoppingCart(ShoppingCart::CartType type);
}


#endif //SHOPPING_CART_H