//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_LAYER_H
#define ANN_LAYER_H

#include "../activation/ActivationFunction.h"

struct Layer
{
    int size;
    ActivationFunction &activation_function;
    Layer(int size, ActivationFunction &activation_function);
};


#endif //ANN_LAYER_H
