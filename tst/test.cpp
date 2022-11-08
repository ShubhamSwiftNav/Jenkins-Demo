#include "gtest/gtest.h"
#include "../src/Factorial.h"
TEST(FactorialValueTest, FactorialOf3) { ASSERT_EQ(Factorial::GetFactorial(3), 6); }
TEST(FactorialValueTest, FactorialOf0) { ASSERT_EQ(Factorial::GetFactorial(0), 1); }
TEST(FactorialValueTest, FactorialOf14) { ASSERT_EQ(Factorial::GetFactorial(14), 87178291200); }
