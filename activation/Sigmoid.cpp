//
// Created by ChrisKim on 24-4-28.
//

#include "Sigmoid.h"
#include <cmath>

double Sigmoid::activate(double x) {
    return 1.0 / (1.0 + exp(-x));
}

Matrix Sigmoid::activate(const Matrix &m) {
    Matrix result(m.height(), m.length());
    for (int i = 0; i < m.height(); i++) {
        for (int j = 0; j < m.length(); j++) {
            result[i][j] = activate(m[i][j]);
        }
    }
    return result;
}

double Sigmoid::derivative(double x) {
    return x * (1.0 - x);
}

Matrix Sigmoid::derivative(const Matrix &m) {
    Matrix result(m.height(), m.length());
    for (int i = 0; i < m.height(); i++) {
        for (int j = 0; j < m.length(); j++) {
            result[i][j] = derivative(m[i][j]);
        }
    }
    return result;
}
