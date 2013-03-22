#include "gtest/gtest.h"

int add(int no1, int no2) {
    return no1 + no2;
}
int subtract(int no1, int no2) {
    return no1 - no2;
}
int multiply(int no1, int no2) {
    return no1 * no2;
}

TEST (MathTests, Addition) {
    ASSERT_TRUE (12 == add(9,3));
    ASSERT_TRUE (23 == add(19,4));
    ASSERT_TRUE (34 == add(31,3));
}

TEST (MathTests, Subtraction) {
    ASSERT_EQ (24, subtract(29,5)) << "Subtraction failed for 29 and 5";
    ASSERT_EQ (35, subtract(42,7)) << "Subtraction failed for 42 and 7";
    ASSERT_EQ (68, subtract(77,9)) << "Subtraction failed for 77 and 9";
}

TEST (MathTests, Multiplication) {
    EXPECT_EQ (45, multiply(9,5))   << "Multiplication failed for 9 and 5";
    EXPECT_EQ (168, multiply(56,3)) << "Multiplication failed for 56 and 3";
    EXPECT_EQ (63, multiply(9,7))   << "Multiplication failed for 9 and 7";
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}




