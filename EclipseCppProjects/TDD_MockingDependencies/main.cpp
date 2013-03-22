#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "iostream"
#include "vector"
#include "map"
#include "string"

using namespace std;
using ::testing::Exactly;
using ::testing::Return;

class StockCheckEngine {
public:
	virtual int checkQuantityInStock(string id) = 0;
};

class MockStockCheckEngine : public StockCheckEngine {
public:
	MOCK_METHOD1(checkQuantityInStock, int(string id));
};

class Shop {
public:
    Shop(StockCheckEngine * stockEngine) {
        this->stockEngine = stockEngine;
    }
    bool purchaseItems(map<string,int> theItems, vector<string>& itemsNotAvailable) {
        bool retval = true;

        map<string,int>::iterator iter;
        for(iter = theItems.begin(); iter != theItems.end(); iter++) {
            string itemId = iter->first;
            int quantityRequired = iter->second;

            int quantityInStock = stockEngine->checkQuantityInStock(itemId);

            cout << "Require " << quantityRequired << " of " << itemId
                 << " found " << quantityInStock << endl;
            if(quantityInStock < quantityRequired) {
                itemsNotAvailable.push_back(itemId);
                retval = false;
            }
        }
        return retval;
    }
private:
    StockCheckEngine * stockEngine;
};


TEST (ShopTests, PurchaseWithAllItemsInStock) {
    MockStockCheckEngine mse;
    Shop shop(&mse);

    EXPECT_CALL(mse, checkQuantityInStock("AB12")).Times(Exactly(1)).WillOnce(Return(20));
    EXPECT_CALL(mse, checkQuantityInStock("CD34")).Times(Exactly(1)).WillOnce(Return(21));
    EXPECT_CALL(mse, checkQuantityInStock("EF56")).Times(Exactly(1)).WillOnce(Return(22));

    map<string,int> itemsToOrder;
    itemsToOrder.insert(pair<string,int>("AB12",15));
    itemsToOrder.insert(pair<string,int>("CD34",16));
    itemsToOrder.insert(pair<string,int>("EF56",17));

    vector<string> itemsUnderstocked;
    EXPECT_TRUE(shop.purchaseItems(itemsToOrder,itemsUnderstocked));
    EXPECT_EQ(0,itemsUnderstocked.size()) << "No items should be understocked";
}

TEST (ShopTests, PurchaseWithSomeUnderstockedItems) {
    MockStockCheckEngine mse;
    Shop shop(&mse);

    EXPECT_CALL(mse, checkQuantityInStock("AB12")).Times(Exactly(1)).WillOnce(Return(14));
    EXPECT_CALL(mse, checkQuantityInStock("CD34")).Times(Exactly(1)).WillOnce(Return(21));
    EXPECT_CALL(mse, checkQuantityInStock("EF56")).Times(Exactly(1)).WillOnce(Return(16));

    map<string,int> itemsToOrder;
    itemsToOrder.insert(pair<string,int>("AB12",15));
    itemsToOrder.insert(pair<string,int>("CD34",16));
    itemsToOrder.insert(pair<string,int>("EF56",17));

    vector<string> itemsUnderstocked;
    EXPECT_FALSE(shop.purchaseItems(itemsToOrder,itemsUnderstocked));
    EXPECT_EQ(2,itemsUnderstocked.size()) << "Two items should be understocked";
    EXPECT_EQ(string("AB12"),itemsUnderstocked[0]);
    EXPECT_EQ(string("EF56"),itemsUnderstocked[1]);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}







