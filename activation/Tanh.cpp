//
// Created by ChrisKim on 24-4-28.
//

#include "Tanh.h"

double Tanh::activate(double x) {
    return tanh(x);
}

Matrix Tanh::activate(const Matrix &m) {
    Matrix result(m);
    result.perform([](double x) { return tanh(x); });
    return result;
}

double Tanh::derivative(double x) {
    return 1 - tanh(x) * tanh(x);
}

Matrix Tanh::derivative(const Matrix &m) {
    Matrix result(m);
    result.perform([](double x) { return 1 - tanh(x) * tanh(x); });
    return result;
}
