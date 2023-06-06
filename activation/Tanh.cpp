//
// Created by ChrisKim on 2023/6/5.
//

#include <cmath>
#include "Tanh.h"

double Tanh::f(double x)
{
    return tanh(x);
}

double Tanh::df(double x)
{
    return 1.0 - pow(tanh(x), 2);
}
