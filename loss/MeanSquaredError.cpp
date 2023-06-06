//
// Created by ChrisKim on 2023/6/6.
//

#include "MeanSquaredError.h"

double MeanSquaredError::f(const Vector &a, const Vector &b)
{
    double result = 0.0;
    for (int i = 0; i < a.height(); i++)
    {
        result += (a.get(i) - b.get(i)) * (a.get(i) - b.get(i));
    }
    return result;
}

Vector MeanSquaredError::df(const Vector &a, const Vector &b)
{
    Vector result(a.height());
    for (int i = 0; i < a.height(); i++)
    {
        result.get(i) = 2 * (a.get(i) - b.get(i));
    }
    return result;
}
