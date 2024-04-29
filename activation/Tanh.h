//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_TANH_H
#define ANN_TANH_H


#include "ActivationFunction.h"

struct Tanh : public ActivationFunction {
    double activate(double x) override;

    Matrix activate(const Matrix &m) override;

    double derivative(double x) override;

    Matrix derivative(const Matrix &m) override;
};


#endif //ANN_TANH_H
