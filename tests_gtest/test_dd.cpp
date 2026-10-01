#include <gtest/gtest.h>
#include "divided_difference.h"

TEST(DividedDifference, SquareFunction) {
    // Для x^2: f[x0,x1,x2] = f''/2! = 2/2 = 1
    EXPECT_DOUBLE_EQ(divided_difference_right(0.0, 1.0, 2.0, square), 1.0);
    EXPECT_DOUBLE_EQ(divided_difference_right(1.0, 3.0, 5.0, square), 1.0);
    EXPECT_DOUBLE_EQ(divided_difference_right(-1.0, 0.0, 1.0, square), 1.0);
    EXPECT_DOUBLE_EQ(divided_difference_right(10.0, 20.0, 30.0, square), 1.0);
}

TEST(DividedDifference, CubeFunction) {
    // Для x^3: f[x0,x1,x2] = x0 + x1 + x2
    EXPECT_DOUBLE_EQ(divided_difference_right(0.0, 1.0, 2.0, cube), 3.0);
    EXPECT_DOUBLE_EQ(divided_difference_right(2.0, 3.0, 4.0, cube), 9.0);
    EXPECT_DOUBLE_EQ(divided_difference_right(-1.0, 1.0, 3.0, cube), 3.0);
}

TEST(DividedDifference, ClosePoints) {
    EXPECT_NEAR(divided_difference_right(1.0, 1.001, 1.002, square), 1.0, 1e-4);
}