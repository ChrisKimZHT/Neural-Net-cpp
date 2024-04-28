//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_RELU_H
#define ANN_RELU_H


#include "ActivationFunction.h"

struct ReLu : public ActivationFunction {
    double activate(double x) override;

    Matrix activate(const Matrix &m) override;

    double derivative(double x) override;

    Matrix derivative(const Matrix &m) override;
};


#endif //ANN_RELU_H
