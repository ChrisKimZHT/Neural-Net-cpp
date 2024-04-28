//
// Created by ChrisKim on 24-4-28.
//

#include "Network.h"

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

void Network::train(const std::vector<Matrix> &input, const std::vector<Matrix> &target,
                    LossFunction *loss_function, int epochs, double learning_rate) {
    for (int epoch = 0; epoch < epochs; epoch++) {
        double loss = 0;
        for (int i = 0; i < input.size(); i++) {
            Matrix output = forward(input[i]);
            loss += loss_function->loss(output, target[i]);
            Matrix d_output = loss_function->derivative(output, target[i]);
            for (auto it = layers.rbegin(); it != layers.rend(); ++it) {
                d_output = (*it)->backward(d_output, learning_rate);
            }
        }
        std::cout << "Epoch: " << epoch << " Loss: " << loss << std::endl;
    }
}

Matrix Network::predict(const Matrix &input) {
    return forward(input);
}




