//
// Created by ChrisKim on 24-5-29.
//

#ifndef ANN_DROPOUTLAYER_H
#define ANN_DROPOUTLAYER_H


#include "Layer.h"

struct DropoutLayer : public Layer {
    double dropout_rate;
    Matrix mask;

    explicit DropoutLayer(double dropout_rate);

    Matrix forward(const Matrix &input) override;

    Matrix backward(const Matrix &d_output, double learning_rate) override;
};


#endif //ANN_DROPOUTLAYER_H
