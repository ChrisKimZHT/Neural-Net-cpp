//
// Created by ChrisKim on 2023/6/5.
//

#include "ReLU.h"

double ReLU::f(double x)
{
    return x > 0.0 ? x : 0.0;
}

double ReLU::df(double x)
{
    return x > 0.0 ? 1.0 : 0.0;
}
