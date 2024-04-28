//
// Created by ChrisKim on 24-4-28.
//

#include "MeanSquaredError.h"

double MeanSquaredError::loss(const Matrix &output, const Matrix &target) {
    double result = 0;
    for (int i = 0; i < output.height(); i++) {
        result += pow(output[i][0] - target[i][0], 2);
    }
    return result / output.height();
}

Matrix MeanSquaredError::derivative(const Matrix &output, const Matrix &target) {
    return (output - target) * 2 / output.height();
}
