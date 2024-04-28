//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_LOSSFUNCTION_H
#define ANN_LOSSFUNCTION_H


#include "../matrix/Matrix.h"

class LossFunction {
public:
    virtual double loss(const Matrix &output, const Matrix &target) = 0;

    virtual Matrix derivative(const Matrix &output, const Matrix &target) = 0;
};


#endif //ANN_LOSSFUNCTION_H
