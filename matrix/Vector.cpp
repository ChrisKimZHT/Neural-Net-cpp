//
// Created by ChrisKim on 2023/6/6.
//

#include "Vector.h"

Vector::Vector(int dimension, double val)
        : Matrix(dimension, 1, val) {}

double &Vector::get(int idx)
{
    return _data[idx][0];
}

double Vector::get(int idx) const
{
    return _data[idx][0];
}

