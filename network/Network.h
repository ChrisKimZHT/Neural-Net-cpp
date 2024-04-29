//
// Created by ChrisKim on 24-4-28.
//

#ifndef ANN_NETWORK_H
#define ANN_NETWORK_H


#include <vector>
#include "../layer/Layer.h"
#include "../loss/LossFunction.h"

class Network {
private:
    std::vector<Layer *> layers;

public:
    explicit Network() = default;

    explicit Network(std::vector<Layer *> layers) : layers(std::move(layers)) {};

    void add_layer(Layer *layer);

    double train(const std::vector<Matrix> &input, const std::vector<Matrix> &target,
                 LossFunction *loss_function, int epochs, double learning_rate);

    Matrix predict(const Matrix &input);

    double evaluate(const std::vector<Matrix> &input, const std::vector<Matrix> &target,
                    LossFunction *loss_function, bool one_hot_encoding = false);
};


#endif //ANN_NETWORK_H
