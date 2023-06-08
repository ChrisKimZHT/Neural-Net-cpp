//
// Created by ChrisKim on 2023/6/8.
//

#ifndef ANN_LOADPLANE_H
#define ANN_LOADPLANE_H

#include <vector>
#include <string>
#include <utility>
#include <random>
#include <chrono>
#include "../matrix/Matrix.h"

std::vector<std::pair<Matrix, Matrix>> load_plane(int size, const std::string& type);

#endif //ANN_LOADPLANE_H
