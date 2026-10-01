#include <iostream>
#include <iomanip>
#include "divided_difference.h"

int main() {
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "Right diff f[x0,x1,x2]\n\n";

    // f(x) = x^2, the second divided difference = f''/2! = 2/2 = 1
    std::cout << "f(x) = x^2 (f''/2! = 2/2 = 1):\n";
    std::cout << " (0, 1, 2): ";
    std::cout << divided_difference_right(0.0, 1.0, 2.0, square) << "\n";
    std::cout << " (1, 3, 5): ";
    std::cout << divided_difference_right(1.0, 3.0, 5.0, square) << "\n";
    std::cout << " (-1, 0, 1) ";
    std::cout << divided_difference_right(-1.0, 0.0, 1.0, square) << "\n";

    std::cout << "\n";

    // f(x) = x^3: f[x0,x1,x2] = x0 + x1 + x2
    std::cout << "f(x) = x^3 (f[x0,x1,x2] = x0+x1+x2):\n";
    std::cout << "  (0, 1, 2): ";
    std::cout << divided_difference_right(0.0, 1.0, 2.0, cube) << " (expected 3)\n";
    std::cout << "  (2, 3, 4): ";
    std::cout << divided_difference_right(2.0, 3.0, 4.0, cube) << " (expected 9)\n";

    return 0;
}