//
// Created by ChrisKim on 24-4-28.
//

#include "ReLu.h"

double ReLu::activate(double x) {
    return x > 0.0 ? x : 0.0;
}

Matrix ReLu::activate(const Matrix &m) {
    Matrix result(m);
    result.perform([](double x) { return x > 0.0 ? x : 0.0; });
    return result;
}

double ReLu::derivative(double x) {
    return x > 0.0 ? 1.0 : 0.0;
}

Matrix ReLu::derivative(const Matrix &m) {
    Matrix result(m);
    result.perform([](double x) { return x > 0.0 ? 1.0 : 0.0; });
    return result;
}
