//
// Created by ChrisKim on 24-4-28.
//

#include "Sigmoid.h"
#include <cmath>

double Sigmoid::activate(double x) {
    return 1.0 / (1.0 + exp(-x));
}

Matrix Sigmoid::activate(const Matrix &m) {
    Matrix result(m);
    result.perform([](double x) { return 1.0 / (1.0 + exp(-x)); });
    return result;
}

double Sigmoid::derivative(double x) {
    return 1.0 / (1.0 + exp(-x)) * (1.0 - 1.0 / (1.0 + exp(-x)));
}

Matrix Sigmoid::derivative(const Matrix &m) {
    Matrix result(m);
    result.perform([](double x) { return 1.0 / (1.0 + exp(-x)) * (1.0 - 1.0 / (1.0 + exp(-x))); });
    return result;
}
