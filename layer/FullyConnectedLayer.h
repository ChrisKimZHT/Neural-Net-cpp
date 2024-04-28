//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_FULLYCONNECTEDLAYER_H
#define ANN_FULLYCONNECTEDLAYER_H


#include "Layer.h"

struct FullyConnectedLayer : public Layer {
    Matrix weights, biases;

    FullyConnectedLayer(int input_size, int output_size);

    Matrix forward(const Matrix &input) override;

    Matrix backward(const Matrix &d_output, double learning_rate) override;
};


#endif //ANN_FULLYCONNECTEDLAYER_H
