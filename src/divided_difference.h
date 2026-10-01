#pragma once

// Правая разделённая разность для трёх точек
// f[x0, x1, x2] = (f[x1, x2] - f[x0, x1]) / (x2 - x0)
double divided_difference_right(double x0, double x1, double x2,
                                 double (*f)(double));

// Пример функции для тестов
double square(double x);
double cube(double x);