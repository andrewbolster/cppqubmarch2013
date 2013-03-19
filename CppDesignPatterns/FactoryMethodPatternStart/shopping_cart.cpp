#include "shopping_cart.h"

namespace demo {
	ShoppingCart * buildShoppingCart(ShoppingCart::CartType type) {
		if(type == ShoppingCart::STANDARD) {
			return new StandardShoppingCart;
		} else {
			return new BusinessShoppingCart;
		}
	}
}