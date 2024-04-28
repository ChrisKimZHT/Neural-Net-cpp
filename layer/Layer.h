//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_LAYER_H
#define ANN_LAYER_H

#include "../matrix/Matrix.h"

struct Layer {
    Matrix input, output;

    virtual Matrix forward(const Matrix &input) = 0;

    virtual Matrix backward(const Matrix &d_output, double learning_rate) = 0;
};


#endif //ANN_LAYER_H
