//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_ACTIVATIONFUNCTION_H
#define ANN_ACTIVATIONFUNCTION_H


#include "../matrix/Matrix.h"

struct ActivationFunction {
public:
    virtual double activate(double x) = 0;

    virtual Matrix activate(const Matrix &m) = 0;

    virtual double derivative(double x) = 0;

    virtual Matrix derivative(const Matrix &m) = 0;
};


#endif //ANN_ACTIVATIONFUNCTION_H
