//
// Created by ChrisKim on 2023/6/5.
//

#ifndef ANN_RELU_H
#define ANN_RELU_H

#include "ActivationFunction.h"

class ReLU : public ActivationFunction
{
public:
    double f(double x) final;
    double df(double x) final;
};


#endif //ANN_RELU_H
