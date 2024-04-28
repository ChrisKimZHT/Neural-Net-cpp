//
// Created by ChrisKim on 24-4-28.
//

#include "Network.h"

Network::Network(LossFunction *loss_function) {
    this->loss_function = loss_function;
}

void Network::add_layer(Layer *layer) {
    layers.push_back(layer);
}

Matrix Network::forward(const Matrix &input) {
    Matrix output = input;
    for (auto &layer: layers) {
        output = layer->forward(output);
    }
    return output;
}

double
Network::train(const std::vector<Matrix> &input, const std::vector<Matrix> &target, int epochs, double learning_rate) {
    double loss = 0;
    for (int epoch = 0; epoch < epochs; epoch++) {
        for (int i = 0; i < input.size(); i++) {
            Matrix output = forward(input[i]);
            loss += loss_function->loss(output, target[i]);
            Matrix d_output = loss_function->derivative(output, target[i]);
            for (int j = layers.size() - 1; j >= 0; j--) {
                d_output = layers[j]->backward(d_output, learning_rate);
            }
        }
        std::cout << "Epoch: " << epoch << " Loss: " << loss << std::endl;
    }
    return loss;
}

Matrix Network::predict(const Matrix &input) {
    return forward(input);
}




