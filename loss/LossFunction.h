//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_LOSSFUNCTION_H
#define ANN_LOSSFUNCTION_H

#include "../matrix/Vector.h"

class LossFunction
{
public:
    virtual double f(const Vector &a, const Vector &b);
    virtual Vector df(const Vector &a, const Vector &b);
};


#endif //ANN_LOSSFUNCTION_H
