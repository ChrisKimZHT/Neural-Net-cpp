//
// Created by ChrisKim on 2023/6/8.
//

#ifndef ANN_TESTCASEFILE_H
#define ANN_TESTCASEFILE_H

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "../matrix/Matrix.h"

std::vector<std::pair<Matrix, Matrix>> load_testcase(const std::string& filename);
void save_testcase(const std::string& filename, std::vector<std::pair<Matrix, Matrix>> &data);

#endif //ANN_TESTCASEFILE_H
