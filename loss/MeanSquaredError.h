//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_MEANSQUAREDERROR_H
#define ANN_MEANSQUAREDERROR_H

#include "LossFunction.h"

class MeanSquaredError : public LossFunction
{
public:
    double f(const Matrix &a, const Matrix &b) final;
    Matrix df(const Matrix &a, const Matrix &b) final;
};


#endif //ANN_MEANSQUAREDERROR_H
