//
// Created by ChrisKim on 2023/6/6.
//

#include "LoadPolynomial.h"

std::vector<std::pair<Matrix, Matrix>> load_polynomial(int size, double(*f)(double))
{
    std::vector<std::pair<Matrix, Matrix>> data;
    double x = 0.0;
    for (int i = 0; i < size; i++)
    {
        x += 1.0 * rand() / RAND_MAX;
        double y = f(x);
        data.emplace_back(Matrix(1, 1, x), Matrix(1, 1, y));
    }
    return data;
}
