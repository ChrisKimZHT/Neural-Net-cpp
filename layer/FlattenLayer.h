//
// Created by ChrisKim on 24-4-29.
//

#ifndef ANN_FLATTENLAYER_H
#define ANN_FLATTENLAYER_H


#include "Layer.h"

struct FlattenLayer : public Layer {
    Matrix forward(const Matrix &input) override;

    Matrix backward(const Matrix &d_output, double learning_rate) override;
};


#endif //ANN_FLATTENLAYER_H
