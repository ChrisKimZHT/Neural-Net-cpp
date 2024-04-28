//
// Created by ChrisKim on 2023/6/8.
//

#ifndef ANN_SAVEPLANEMESH_H
#define ANN_SAVEPLANEMESH_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../matrix/Matrix.h"
#include "../network/Network.h"

void save_plane_mesh(double x_start, double x_end, double x_step,
                     double y_start, double y_end, double y_step,
                     Network &network, const std::string &filename);

#endif //ANN_SAVEPLANEMESH_H
