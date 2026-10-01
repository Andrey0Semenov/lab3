#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "divided_difference.h"

TEST_CASE("Right divided difference for f(x) = x^2", "[dd][square]") {
    // Для x^2: f[x0,x1,x2] = f''/2! = 2/2 = 1
    REQUIRE(divided_difference_right(0.0, 1.0, 2.0, square) == Approx(1.0));
    REQUIRE(divided_difference_right(1.0, 3.0, 5.0, square) == Approx(1.0));
    REQUIRE(divided_difference_right(-1.0, 0.0, 1.0, square) == Approx(1.0));
    REQUIRE(divided_difference_right(10.0, 20.0, 30.0, square) == Approx(1.0));
}

TEST_CASE("Right divided difference for f(x) = x^3", "[dd][cube]") {
    // Для x^3: f[x0,x1,x2] = x0 + x1 + x2
    REQUIRE(divided_difference_right(0.0, 1.0, 2.0, cube) == Approx(3.0));
    REQUIRE(divided_difference_right(2.0, 3.0, 4.0, cube) == Approx(9.0));
    REQUIRE(divided_difference_right(-1.0, 1.0, 3.0, cube) == Approx(3.0));
}

TEST_CASE("Right divided difference on close points", "[dd][precision]") {
    REQUIRE(divided_difference_right(1.0, 1.001, 1.002, square) == Approx(1.0).epsilon(1e-4));
}