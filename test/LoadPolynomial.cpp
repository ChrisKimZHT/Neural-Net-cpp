//
// Created by ChrisKim on 2023/6/6.
//

#include "LoadPolynomial.h"


std::vector<std::pair<Matrix, Matrix>>
load_polynomial(int size, double(*f)(double), double min, double max)
{
    std::vector<std::pair<Matrix, Matrix>> data;
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::uniform_real_distribution<double> distribution(min, max);
    for (int i = 0; i < size; i++)
    {
        double x = distribution(generator);
        double y = f(x);
        data.emplace_back(Matrix(1, 1, x), Matrix(1, 1, y));
    }
    return data;
}
