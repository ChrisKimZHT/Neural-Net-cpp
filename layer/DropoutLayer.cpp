//
// Created by ChrisKim on 24-5-29.
//

#include "DropoutLayer.h"

DropoutLayer::DropoutLayer(double dropout_rate) {
    this->dropout_rate = dropout_rate;
}

Matrix DropoutLayer::forward(const Matrix &input, bool is_eval) {
    if (is_eval) {
        return input;
    }
    mask = Matrix(input.row(), input.col());
    mask.randomize(0, 1);
    for (int i = 0; i < input.row(); i++) {
        for (int j = 0; j < input.col(); j++) {
            mask(i, j) = mask(i, j) < dropout_rate ? 0 : 1;
        }
    }
    return input.hadamard(mask) / (1 - dropout_rate);
}

Matrix DropoutLayer::backward(const Matrix &d_output, double learning_rate) {
    return d_output.hadamard(mask) / (1 - dropout_rate);
}
