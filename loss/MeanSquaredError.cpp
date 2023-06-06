//
// Created by ChrisKim on 2023/6/6.
//

#include "MeanSquaredError.h"

double MeanSquaredError::f(const Matrix &a, const Matrix &b)
{
    double result = 0.0;
    for (int i = 0; i < a.height(); i++)
    {
        result += (a[i][0] - b[i][0]) * (a[i][0] - b[i][0]);
    }
    return result;
}

Matrix MeanSquaredError::df(const Matrix &a, const Matrix &b)
{
    Matrix result(a.height(), 1);
    for (int i = 0; i < a.height(); i++)
    {
        result[i][0] = 2 * (a[i][0] - b[i][0]);
    }
    return result;
}
