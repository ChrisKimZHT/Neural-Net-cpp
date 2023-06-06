//
// Created by ChrisKim on 2023/6/5.
//
#include <cmath>
#include "Sigmoid.h"

double Sigmoid::f(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

double Sigmoid::df(double x)
{
    return f(x) * (1 - f(x));
}
