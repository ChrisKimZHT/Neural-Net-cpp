//
// Created by ChrisKim on 2023/6/6.
//

#ifndef ANN_LOADPOLYNOMIAL_H
#define ANN_LOADPOLYNOMIAL_H

#include <vector>
#include <utility>
#include "../matrix/Matrix.h"

std::vector<std::pair<Matrix, Matrix>> load_polynomial(int size, double(*f)(double));


#endif //ANN_LOADPOLYNOMIAL_H
