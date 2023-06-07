//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_COMPILEDMODEL_H
#define ANN_COMPILEDMODEL_H

#include <vector>
#include <random>
#include <utility>
#include "Layer.h"
#include "../loss/LossFunction.h"
#include "../activation/ActivationFunction.h"
#include "../matrix/Matrix.h"

class CompiledModel
{
private:
    int input_dim;
    double learning_rate;
    int batch_size; // not implemented yet
    LossFunction &loss_function;
    std::vector<Layer> layers;

    std::vector<ActivationFunction *> activation_functions;
    std::vector<Matrix> weights;
    std::vector<Matrix> delta_weights;
    std::vector<Matrix> biases;
    std::vector<Matrix> delta_biases;
    std::vector<Matrix> outputs;
    std::vector<Matrix> activated_outputs;
    Matrix current_input;
    double loss;
    Matrix d_loss;

    std::default_random_engine generator;
    std::normal_distribution<double> distribution;
    std::random_device rd;
    std::mt19937 mtgen;
    void rand_matrix(Matrix &matrix);

    static Matrix activate(Matrix matrix, ActivationFunction *activation_function);
    void calc_loss(Matrix &labels);
    void back_propagation();
    void update_parameters();

public:
    CompiledModel(int input_dim,
                  double learning_rate,
                  int batch_size,
                  LossFunction &loss_function,
                  std::vector<Layer> layers);
    Matrix predict(Matrix &data);
    void fit(std::vector<std::pair<Matrix, Matrix>> &input, int epochs);
};


#endif //ANN_COMPILEDMODEL_H
