#include<iostream>
#include<string>

#include "shopping_cart.h"

using std::string;
using std::cout;
using std::endl;

using namespace demo;

int main() {

	ShoppingCart * cart1 = buildShoppingCart(ShoppingCart::STANDARD);
	cart1->add("item1");
	cart1->add("item2");
	cart1->add("item3");
	cart1->add("item4");
	cart1->listContents();

	ShoppingCart * cart2 = buildShoppingCart(ShoppingCart::BUSINESS);
	cart2->add("item1");
	cart2->add("item2");
	cart2->add("item3");
	cart2->add("item4");
	cart2->listContents();

	delete cart1;
	delete cart2;
}