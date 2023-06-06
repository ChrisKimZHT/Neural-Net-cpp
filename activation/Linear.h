//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_LINEAR_H
#define ANN_LINEAR_H

#include "ActivationFunction.h"

class Linear : public ActivationFunction
{
public:
    double f(double x) final;
    double df(double x) final;
};


#endif //ANN_LINEAR_H
