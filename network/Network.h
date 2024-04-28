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
    LossFunction *loss_function;

public:
    explicit Network(LossFunction *loss_function);

    void add_layer(Layer *layer);

    Matrix forward(const Matrix &input);

    void train(const std::vector<Matrix> &input, const std::vector<Matrix> &target, int epochs, double learning_rate);

    Matrix predict(const Matrix &input);
};


#endif //ANN_NETWORK_H
