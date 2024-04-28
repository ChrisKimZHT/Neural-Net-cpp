//
// Created by ChrisKim on 24-4-28.
//

#include "MeanSquaredError.h"

double MeanSquaredError::loss(const Matrix &predict, const Matrix &ground_truth) {
    double result = 0;
    for (int i = 0; i < predict.height(); i++) {
        result += pow(predict[i][0] - ground_truth[i][0], 2);
    }
    return result / predict.height();
}

Matrix MeanSquaredError::derivative(const Matrix &predict, const Matrix &ground_truth) {
    return (predict - ground_truth) * 2 / predict.height();
}
