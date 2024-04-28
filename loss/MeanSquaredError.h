//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_MEANSQUAREDERROR_H
#define ANN_MEANSQUAREDERROR_H


#include "LossFunction.h"

struct MeanSquaredError : public LossFunction {
    double loss(const Matrix &predict, const Matrix &ground_truth) override;

    Matrix derivative(const Matrix &predict, const Matrix &ground_truth) override;
};


#endif //ANN_MEANSQUAREDERROR_H
