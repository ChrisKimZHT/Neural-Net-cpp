//
// Created by ChrisKim on 24-4-28.
//

#include "FullyConnectedLayer.h"

FullyConnectedLayer::FullyConnectedLayer(int input_size, int output_size) :
        input_size(input_size), output_size(output_size) {
    weights = Matrix(output_size, input_size);
    biases = Matrix(output_size, 1);
    weights.randomize();
    biases.randomize();
}

Matrix FullyConnectedLayer::forward(const Matrix &input, bool is_eval) {
    this->input = input;
    return weights * input + biases;
}

Matrix FullyConnectedLayer::backward(const Matrix &d_output, double learning_rate) {
    Matrix d_input = weights.transpose() * d_output;
    Matrix d_weights = d_output * input.transpose();
    const Matrix &d_biases = d_output;
    weights -= d_weights * learning_rate;
    biases -= d_biases * learning_rate;
    return d_input;
}