//
// Created by ChrisKim on 2023/6/5.
//

#ifndef ANN_ACTIVATIONFUNCTION_H
#define ANN_ACTIVATIONFUNCTION_H

// Abstract class for activation function
class ActivationFunction
{
public:
    virtual double f(double x);
    virtual double df(double x);
};

#endif //ANN_ACTIVATIONFUNCTION_H
