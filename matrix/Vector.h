//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_VECTOR_H
#define ANN_VECTOR_H

#include "Matrix.h"

class Vector : public Matrix
{
public:
    Vector() = default;
    explicit Vector(int dimension, double val = 0);
    double &get(int idx);
    [[nodiscard]] double get(int idx) const;
};


#endif //ANN_VECTOR_H
