//
// Created by ChrisKim on 2023/6/6.
//

#include <iostream>
#include "LossFunction.h"

double LossFunction::f(const Matrix &a, const Matrix &b)
{
    std::cerr << "The LossFunction class is an abstract class, you should not call this function." << std::endl;
    exit(1);
}

Matrix LossFunction::df(const Matrix &a, const Matrix &b)
{
    std::cerr << "The LossFunction class is an abstract class, you should not call this function." << std::endl;
    exit(1);
}
