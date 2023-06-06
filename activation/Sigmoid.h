//
// Created by ChrisKim on 2023/6/5.
//

#ifndef ANN_SIGMOID_H
#define ANN_SIGMOID_H

#include "ActivationFunction.h"

class Sigmoid : public ActivationFunction
{
public:
    double f(double x) final;
    double df(double x) final;
};


#endif //ANN_SIGMOID_H
