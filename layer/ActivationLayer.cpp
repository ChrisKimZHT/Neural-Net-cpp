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
    return activation_function->derivative(input) * d_output;
}
