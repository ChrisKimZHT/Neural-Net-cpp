//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_LAYER_H
#define ANN_LAYER_H

#include "../matrix/Matrix.h"

struct Layer {
    Matrix input;

    virtual Matrix forward(const Matrix &input, bool is_eval) = 0;

    virtual Matrix backward(const Matrix &d_output, double is_eval) = 0;
};


#endif //ANN_LAYER_H
