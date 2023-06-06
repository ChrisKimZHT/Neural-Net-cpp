//
// Created by ChrisKim on 2023/6/5.
//

#ifndef ANN_TANH_H
#define ANN_TANH_H

#include "ActivationFunction.h"

class Tanh : public ActivationFunction
{
public:
    double f(double x) final;
    double df(double x) final;
};


#endif //ANN_TANH_H
