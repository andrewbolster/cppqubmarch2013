#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include<string>

using std::string;

namespace demo {

	class ShoppingCart {
	public:
		ShoppingCart();
		~ShoppingCart();
		enum CartType {STANDARD, BUSINESS};
		//add should create the list if it doesnt already exist
		void add(string item);
		void listContents();
	protected:
		//virtual method to build list goes here...
	private:
		//pointer to list goes here...

	};

	class StandardShoppingCart : public ShoppingCart {
	protected:
		//override method to build list here...
	};

	class BusinessShoppingCart : public ShoppingCart {
		//override method to build list here...
	};

	//A factory method for building carts
	ShoppingCart * buildShoppingCart(ShoppingCart::CartType type);
}


#endif //SHOPPING_CART_H