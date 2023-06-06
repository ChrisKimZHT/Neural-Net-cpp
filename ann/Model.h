//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_MODEL_H
#define ANN_MODEL_H

#include <vector>
#include "../loss/LossFunction.h"
#include "Layer.h"
#include "CompiledModel.h"

class Model
{
private:
    std::vector<Layer> layers;
public:
    explicit Model(std::vector<Layer> layers = std::vector<Layer>());
    void add_layer(const Layer &layer);
    CompiledModel compile(int input_dim, double learning_rate, int batch_size, LossFunction &loss_function);
};


#endif //ANN_MODEL_H
