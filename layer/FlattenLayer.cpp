//
// Created by ChrisKim on 24-4-29.
//

#include "FlattenLayer.h"

Matrix FlattenLayer::forward(const Matrix &input) {
    this->input = input;
    return input.reshape(input.row() * input.col(), 1);
}

Matrix FlattenLayer::backward(const Matrix &d_output, double learning_rate) {
    return d_output.reshape(input.row(), input.col());
}
