//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_MEANSQUAREDERROR_H
#define ANN_MEANSQUAREDERROR_H


#include "LossFunction.h"

class MeanSquaredError : public LossFunction {
public:
    double loss(const Matrix &output, const Matrix &target) override;

    Matrix derivative(const Matrix &output, const Matrix &target) override;
};


#endif //ANN_MEANSQUAREDERROR_H
