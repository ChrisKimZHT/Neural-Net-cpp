//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_ACTIVATIONLAYER_H
#define ANN_ACTIVATIONLAYER_H


#include "Layer.h"
#include "../activation/ActivationFunction.h"

struct ActivationLayer : public Layer {
    ActivationFunction *activation_function;

    explicit ActivationLayer(ActivationFunction *activation_function);

    Matrix forward(const Matrix &input, bool is_eval) override;

    Matrix backward(const Matrix &d_output, double learning_rate) override;
};


#endif //ANN_ACTIVATIONLAYER_H
