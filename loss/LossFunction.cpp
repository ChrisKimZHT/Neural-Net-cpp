//
// Created by ChrisKim on 2023/6/6.
//

#include <iostream>
#include "LossFunction.h"

double LossFunction::f(const Vector &a, const Vector &b)
{
    std::cerr << "The LossFunction class is an abstract class, you should not call this function." << std::endl;
    exit(1);
}

Vector LossFunction::df(const Vector &a, const Vector &b)
{
    std::cerr << "The LossFunction class is an abstract class, you should not call this function." << std::endl;
    exit(1);
}
