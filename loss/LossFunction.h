//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_LOSSFUNCTION_H
#define ANN_LOSSFUNCTION_H


#include "../matrix/Matrix.h"

struct LossFunction {
    virtual double loss(const Matrix &predict, const Matrix &ground_truth) = 0;

    virtual Matrix derivative(const Matrix &predict, const Matrix &ground_truth) = 0;
};


#endif //ANN_LOSSFUNCTION_H
