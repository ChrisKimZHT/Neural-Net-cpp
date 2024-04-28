//
// Created by ChrisKim on 24-4-28.
//

#include "ActivationLayer.h"

ActivationLayer::ActivationLayer(ActivationFunction *activation_function) {
    this->activation_function = activation_function;
}

Matrix ActivationLayer::forward(const Matrix &input) {
    this->input = input;
    return activation_function->activate(input);
}

Matrix ActivationLayer::backward(const Matrix &d_output, double learning_rate) {
    return activation_function->derivative(input).hadamard(d_output);
}
