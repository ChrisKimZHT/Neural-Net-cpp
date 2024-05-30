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

std::pair<std::vector<Matrix>, std::vector<Matrix>> load_testcase(const std::string &filename);

void save_testcase(const std::string &filename, std::vector<Matrix> &x, std::vector<Matrix> &y);

std::pair<std::vector<Matrix>, std::vector<Matrix>> load_binary_testcase(const std::string &filename);

void save_binary_testcase(const std::string &filename, std::vector<Matrix> &x, std::vector<Matrix> &y);

#endif //ANN_TESTCASEFILE_H
