//
// Created by ChrisKim on 2023/6/6.
//

#include "CompiledModel.h"
#include <iostream>
#include <utility>
#include <chrono>

void CompiledModel::rand_matrix(Matrix &matrix)
{
    for (int i = 0; i < matrix.height(); i++)
    {
        for (int j = 0; j < matrix.length(); j++)
        {
            matrix[i][j] = distribution(generator);
        }
    }
}

Matrix CompiledModel::activate(Matrix matrix, ActivationFunction *activation_function)
{
    for (int i = 0; i < matrix.height(); i++)
    {
        for (int j = 0; j < matrix.length(); j++)
        {
            matrix[i][j] = activation_function->f(matrix[i][j]);
        }
    }
    return matrix;
}

CompiledModel::CompiledModel(int input_dim,
                             double learning_rate,
                             int batch_size,
                             LossFunction &loss_function,
                             std::vector<Layer> layers)
        : input_dim(input_dim),
          learning_rate(learning_rate),
          batch_size(batch_size),
          loss_function(loss_function),
          layers(std::move(layers))
{
    // Check the number of layers
    if (this->layers.size() <= 2)
    {
        std::cerr << "The number of layers should be greater than 2." << std::endl;
        exit(1);
    }

    // Initialize random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    generator = std::default_random_engine(timestamp);
    distribution = std::normal_distribution<double>(0.0, 1.0);

    // Initialize vectors
    activation_functions = std::vector<ActivationFunction *>();
    weights = std::vector<Matrix>();
    delta_weights = std::vector<Matrix>();
    temp_weights = std::vector<Matrix>();
    biases = std::vector<Matrix>();
    delta_biases = std::vector<Matrix>();
    temp_biases = std::vector<Matrix>();
    outputs = std::vector<Matrix>();
    activated_outputs = std::vector<Matrix>();

    int last_layer_size = input_dim;

    // Initialize parameters
    for (auto &layer: this->layers)
    {
        activation_functions.push_back(&layer.activation_function);
        weights.emplace_back(layer.size, last_layer_size);
        rand_matrix(weights.back());
        delta_weights.emplace_back(layer.size, last_layer_size);
        temp_weights.emplace_back(layer.size, last_layer_size);
        biases.emplace_back(layer.size, 1);
        rand_matrix(biases.back());
        delta_biases.emplace_back(layer.size, 1);
        temp_biases.emplace_back(layer.size, 1);
        outputs.emplace_back(layer.size, 1);
        activated_outputs.emplace_back(layer.size, 1);
        last_layer_size = layer.size;
    }
}

Matrix CompiledModel::predict(Matrix &data)
{
    // Check the size of data
    if (data.height() != input_dim)
    {
        std::cerr << "The size of data should be " << input_dim << "." << std::endl;
        exit(1);
    }

    Matrix res = data;
    for (int i = 0; i < layers.size(); i++)
    {
        outputs[i] = weights[i] * res + biases[i];
        activated_outputs[i] = activate(outputs[i], activation_functions[i]);
        res = activated_outputs[i];
    }

    return res;
}

