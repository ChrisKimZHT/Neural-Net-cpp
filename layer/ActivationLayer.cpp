//
// Created by ChrisKim on 24-4-28.
//

#include "ActivationLayer.h"

ActivationLayer::ActivationLayer(int size, ActivationFunction *activation_function) {
    input = Matrix(size, 1);
    output = Matrix(size, 1);
    this->activation_function = activation_function;
}

Matrix ActivationLayer::forward(const Matrix &input) {
    this->input = input;
    output = activation_function->activate(input);
    return output;
}

Matrix ActivationLayer::backward(const Matrix &d_output, double learning_rate) {
    Matrix result(input.height(), 1);
    for (int i = 0; i < input.height(); i++) {
        result[i][0] = activation_function->derivative(input[i][0]) * d_output[i][0];
    }
    return result;
}
