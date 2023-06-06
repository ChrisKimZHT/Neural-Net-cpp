//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_LOSSFUNCTION_H
#define ANN_LOSSFUNCTION_H

#include "../matrix/Matrix.h"

class LossFunction
{
public:
    virtual double f(const Matrix &a, const Matrix &b);
    virtual Matrix df(const Matrix &a, const Matrix &b);
};


#endif //ANN_LOSSFUNCTION_H
