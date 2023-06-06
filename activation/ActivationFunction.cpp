//
// Created by ChrisKim on 2023/6/5.
//
#include "ActivationFunction.h"
#include <iostream>

double ActivationFunction::f(double x)
{
    std::cerr << "The ActivationFunction class is an abstract class, you should not call this function." << std::endl;
    exit(1);
}

double ActivationFunction::df(double x)
{
    std::cerr << "The ActivationFunction class is an abstract class, you should not call this function." << std::endl;
    exit(1);
}
