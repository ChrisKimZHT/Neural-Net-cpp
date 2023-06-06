//
// Created by ChrisKim on 2023/6/6.
//

#include <utility>
#include "Model.h"

Model::Model(std::vector<Layer> layers) : layers(std::move(layers)) {}

void Model::add_layer(const Layer &layer)
{
    layers.push_back(layer);
}

CompiledModel Model::compile(int input_dim, double learning_rate, int batch_size, LossFunction &loss_function)
{
    return {input_dim, learning_rate, batch_size, loss_function, layers};
}


