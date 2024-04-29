//
// Created by ChrisKim on 24-4-28.
//

#include <iomanip>
#include <chrono>
#include "Network.h"

void Network::add_layer(Layer *layer) {
    layers.push_back(layer);
}

double Network::train(const std::vector<Matrix> &input, const std::vector<Matrix> &target,
                      LossFunction *loss_function, int epochs, double learning_rate) {
    int data_size = int(input.size());
    std::cout << "[Train] " << data_size << " train data\n";
    double loss = 0;
    for (int e = 0; e < epochs; e++) {
        loss = 0;
        auto start = std::chrono::system_clock::now();
        for (int i = 0; i < input.size(); i++) {
            Matrix output = predict(input[i]);
            loss += loss_function->loss(output, target[i]);
            Matrix d_output = loss_function->derivative(output, target[i]);
            for (auto it = layers.rbegin(); it != layers.rend(); ++it) {
                d_output = (*it)->backward(d_output, learning_rate);
            }
            std::cout << "\r[Epoch " << e + 1 << "/" << epochs << "] "
                      << std::right << std::setw(8) << i + 1 << "/"
                      << std::left << std::setw(8) << data_size
                      << "loss: " << std::left << std::setw(12) << std::setprecision(9) << loss / (i + 1) << std::flush;
        }
        auto end = std::chrono::system_clock::now();
        std::cout << " (" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms)"
                  << std::endl;
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
                         LossFunction *loss_function, bool one_hot_encoding) {
    int data_size = int(input.size());
    std::cout << "[Evaluate] " << data_size << " evaluate data\n";
    if (!one_hot_encoding) {
        double loss = 0;
        for (int i = 0; i < input.size(); i++) {
            Matrix output = predict(input[i]);
            loss += loss_function->loss(output, target[i]);
            std::cout << "\r"
                      << std::right << std::setw(8) << i + 1 << "/"
                      << std::left << std::setw(8) << data_size
                      << "loss: " << std::left << std::setw(12) << loss / (i + 1) << std::flush;
        }
        std::cout << std::endl;
        return loss / data_size;
    } else {
        int correct = 0;
        for (int i = 0; i < input.size(); i++) {
            Matrix output = predict(input[i]);
            if (output.argmax().first == target[i].argmax().first) {
                correct++;
            }
            std::cout << "\r"
                      << std::right << std::setw(8) << i + 1 << "/"
                      << std::left << std::setw(8) << data_size
                      << "accuracy: " << std::left << std::setw(4) << double(correct) / (i + 1)
                      << std::flush;
        }
        std::cout << std::endl;
        return double(correct) / data_size;
    }
}
