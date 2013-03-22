#include "map"
#include "string"
#include "gtest/gtest.h"

using namespace std;

int add(int no1, int no2) {
    return no1 + no2;
}
int subtract(int no1, int no2) {
    return no1 - no2;
}
int multiply(int no1, int no2) {
    return no1 * no2;
}

struct TestDataType {
    int first;
    int second;
    int third;
};

map<string,TestDataType> testData;

typedef pair<string,TestDataType> Entry;

class MyTestBase : public ::testing::Test {
protected:
    void SetUp() {
        TestDataType t1 =  {19,12,7};
        TestDataType t2 = {15,19,4};
        TestDataType t3 = {54,6,9};

	testData.insert(Entry("add",t1));
	testData.insert(Entry("subtract",t2));
	testData.insert(Entry("multiply",t3));
    }
    void TearDown() {
        testData.clear();
    }
};

TEST_F (MyTestBase, Addition) {
    TestDataType values = testData["add"];
    int retval = add(values.second, values.third);
    ASSERT_EQ(values.first,retval) << "Addition failed for specified values";
}

TEST_F (MyTestBase, Subtraction) {
    TestDataType values = testData["subtract"];
    int retval = subtract(values.second, values.third);
    ASSERT_EQ(values.first,retval) << "Subtraction failed for specified values";
}

TEST_F (MyTestBase, Multiplication) {
    TestDataType values = testData["multiply"];
    int retval = multiply(values.second, values.third);
    ASSERT_EQ(values.first,retval) << "Multiplication failed for specified values";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}




