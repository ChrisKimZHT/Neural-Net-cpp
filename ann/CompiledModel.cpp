//
// Created by ChrisKim on 2023/6/6.
//

#include "CompiledModel.h"
#include <iostream>
#include <utility>
#include <chrono>
#include <algorithm>
#include <iomanip>

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
    if (this->layers.size() < 2)
    {
        std::cerr << "The number of layers should be greater than 1." << std::endl;
        exit(1);
    }

    // Initialize random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    generator = std::default_random_engine(timestamp);
    distribution = std::normal_distribution<double>(0.0, 1.0);
    mtgen = std::mt19937(rd());

    // Initialize vectors
    activation_functions = std::vector<ActivationFunction *>();
    weights = std::vector<Matrix>();
    delta_weights = std::vector<Matrix>();
    biases = std::vector<Matrix>();
    delta_biases = std::vector<Matrix>();
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
        biases.emplace_back(layer.size, 1);
        rand_matrix(biases.back());
        delta_biases.emplace_back(layer.size, 1);
        outputs.emplace_back(layer.size, 1);
        activated_outputs.emplace_back(layer.size, 1);
        last_layer_size = layer.size;
    }
    current_input = Matrix(input_dim, 1);
    loss = 0.0;
    d_loss = Matrix(last_layer_size, 1);
}

Matrix CompiledModel::predict(Matrix &data)
{
    // Check the size of data
    if (data.height() != input_dim)
    {
        std::cerr << "The size of data should be " << input_dim << "." << std::endl;
        exit(1);
    }

    current_input = data;

    Matrix res = data;
    for (int i = 0; i < layers.size(); i++)
    {
        outputs[i] = weights[i] * res + biases[i];
        activated_outputs[i] = activate(outputs[i], activation_functions[i]);
        res = activated_outputs[i];
    }

    return res;
}

void CompiledModel::calc_loss(Matrix &labels)
{
    loss = loss_function.f(activated_outputs.back(), labels);
    d_loss = loss_function.df(activated_outputs.back(), labels);
}

void CompiledModel::back_propagation()
{
    Matrix d_layer_loss = d_loss;
    for (int i = int(layers.size()) - 1; i >= 0; i--)
    {
        int prev_layer_size = i == 0 ? input_dim : layers[i - 1].size;
        for (int j = 0; j < biases[i].height(); j++)
        {
            delta_biases[i][j][0] = d_layer_loss[j][0] * activation_functions[i]->df(outputs[i][j][0]);
            for (int k = 0; k < prev_layer_size; k++)
            {
                double prev_activated_output = i == 0 ? current_input[k][0] : activated_outputs[i - 1][k][0];
                delta_weights[i][j][k] = delta_biases[i][j][0] * prev_activated_output;
            }
        }
        if (i == 0)
            break;
        Matrix new_d_layer_loss = Matrix(prev_layer_size, 1);
        for (int j = 0; j < prev_layer_size; j++)
        {
            for (int k = 0; k < layers[i].size; k++)
            {
                new_d_layer_loss[j][0] += weights[i][k][j] *
                                          activation_functions[i]->df(outputs[i][k][0]) *
                                          d_layer_loss[k][0];
            }
        }
        d_layer_loss = new_d_layer_loss;
    }
}

void CompiledModel::update_parameters()
{
    for (int i = 0; i < layers.size(); i++)
    {
        biases[i] -= delta_biases[i] * learning_rate;
        weights[i] -= delta_weights[i] * learning_rate;
    }
}

void CompiledModel::fit(std::vector<std::pair<Matrix, Matrix>> &input, int epochs)
{
    int data_size = int(input.size());
    for (int e = 0; e < epochs; e++)
    {
        double epoch_loss = 0.0;
        std::cout << "[Epoch " << e + 1 << "/" << epochs << "]\n";
        std::shuffle(input.begin(), input.end(), mtgen);
        int cnt = 1;
        for (auto &[data, label]: input)
        {
            predict(data);
            calc_loss(label);
            epoch_loss = epoch_loss * (cnt - 1) / cnt + loss / cnt;
            std::cout << "\r"
                      << std::right << std::setw(8) << cnt << "/"
                      << std::left << std::setw(8) << data_size
                      << "loss: " << std::left << std::setw(12) << epoch_loss << std::flush;
            back_propagation();
            update_parameters();
            cnt++;
        }
        std::cout << std::endl;
    }
}

void CompiledModel::evaluate(std::vector<std::pair<Matrix, Matrix>> &input)
{
    int cnt = 1, data_size = int(input.size());
    double evaluate_loss = 0.0;
    for (auto &[data, label]: input)
    {
        predict(data);
        calc_loss(label);
        evaluate_loss = evaluate_loss * (cnt - 1) / cnt + loss / cnt;
        std::cout << "\r"
                  << std::right << std::setw(8) << cnt << "/"
                  << std::left << std::setw(8) << data_size
                  << "loss: " << std::left << std::setw(12) << evaluate_loss << std::flush;
        cnt++;
    }
    std::cout << std::endl;
}

