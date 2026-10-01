#include "divided_difference.h"

double divided_difference_right(double x0, double x1, double x2,
                                 double (*f)(double)) {
    // Первая разделённая разность на [x0, x1]
    double f01 = (f(x1) - f(x0)) / (x1 - x0);
    // Первая разделённая разность на [x1, x2]
    double f12 = (f(x2) - f(x1)) / (x2 - x1);
    // Вторая разделённая разность (правая)
    return (f12 - f01) / (x2 - x0);
}

double square(double x) { return x * x; }
double cube(double x)   { return x * x * x; }