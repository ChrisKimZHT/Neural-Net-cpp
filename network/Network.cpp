//
// Created by ChrisKim on 24-4-28.
//

#include <iomanip>
#include "Network.h"

void Network::add_layer(Layer *layer) {
    layers.push_back(layer);
}

double Network::train(const std::vector<Matrix> &input, const std::vector<Matrix> &target,
                      LossFunction *loss_function, int epochs, double learning_rate) {
    int data_size = int(input.size());
    std::cout << "[Training] " << data_size << " train data\n";
    double loss = 0;
    for (int e = 0; e < epochs; e++) {
        loss = 0;
        std::cout << "[Epoch " << e + 1 << "/" << epochs << "]\n";
        for (int i = 0; i < input.size(); i++) {
            Matrix output = predict(input[i]);
            loss += loss_function->loss(output, target[i]);
            Matrix d_output = loss_function->derivative(output, target[i]);
            for (auto it = layers.rbegin(); it != layers.rend(); ++it) {
                d_output = (*it)->backward(d_output, learning_rate);
            }
            std::cout << "\r"
                      << std::right << std::setw(8) << i + 1 << "/"
                      << std::left << std::setw(8) << data_size
                      << "loss: " << std::left << std::setw(12) << loss / (i + 1) << std::flush;
        }
        std::cout << std::endl;
    }
    return loss / data_size;
}

Matrix Network::predict(const Matrix &input) {
    Matrix output = input;
    for (auto &layer: layers) {
        output = layer->forward(output);
    }
    return output;
}

double Network::evaluate(const std::vector<Matrix> &input, const std::vector<Matrix> &target,
                         LossFunction *loss_function) {
    int data_size = int(input.size());
    std::cout << "[Evaluating] " << data_size << " evaluate data\n";
    double loss = 0;
    for (int i = 0; i < input.size(); i++) {
        Matrix output = predict(input[i]);
        loss += loss_function->loss(output, target[i]);
        std::cout << "\r"
                  << std::right << std::setw(8) << i + 1 << "/"
                  << std::left << std::setw(8) << data_size
                  << "loss: " << std::left << std::setw(12) << loss / (i + 1) << std::flush;
    }
    return loss / data_size;
}
