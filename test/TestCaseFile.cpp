//
// Created by ChrisKim on 2023/6/8.
//

#include "TestCaseFile.h"

std::pair<std::vector<Matrix>, std::vector<Matrix>> load_testcase(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<Matrix> x, y;
    int data_size;
    std::pair<int, int> input_shape;
    std::pair<int, int> label_shape;
    file >> data_size
         >> input_shape.first >> input_shape.second
         >> label_shape.first >> label_shape.second;
    for (int i = 0; i < data_size; i++) {
        std::cout << "\r[Load Dataset] "
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(6) << 100.0 * (i + 1) / data_size << "% "
                  << std::right << std::setw(8) << i + 1 << "/"
                  << std::left << std::setw(8) << data_size << std::flush;
        Matrix input(input_shape.first, input_shape.second);
        Matrix label(label_shape.first, label_shape.second);
        for (int j = 0; j < input_shape.first; j++) {
            for (int k = 0; k < input_shape.second; k++) {
                file >> input(j, k);
            }
        }
        for (int j = 0; j < label_shape.first; j++) {
            for (int k = 0; k < label_shape.second; k++) {
                file >> label(j, k);
            }
        }
        x.push_back(input);
        y.push_back(label);
    }
    std::cout << std::endl;
    return {x, y};
}

void save_testcase(const std::string &filename, std::vector<Matrix> &x, std::vector<Matrix> &y) {
    if (x.size() != y.size()) {
        std::cerr << "Input and label size mismatch" << std::endl;
        exit(1);
    }
    std::ofstream file(filename);
    int data_size = int(x.size());
    std::pair<int, int> input_shape = x.front().shape();
    std::pair<int, int> label_shape = y.front().shape();
    file << data_size << '\n'
         << input_shape.first << ' ' << input_shape.second << '\n'
         << label_shape.first << ' ' << label_shape.second << '\n';
    for (int k = 0; k < data_size; k++) {
        std::cout << "\r[Save Dataset] "
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(6) << 100.0 * (k + 1) / data_size << "% "
                  << std::right << std::setw(8) << k + 1 << "/"
                  << std::left << std::setw(8) << data_size << std::flush;
        auto &input = x[k];
        auto &label = y[k];
        for (int i = 0; i < input_shape.first; i++) {
            for (int j = 0; j < input_shape.second; j++) {
                file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << input(i, j);
            }
        }
        for (int i = 0; i < label_shape.first; i++) {
            for (int j = 0; j < label_shape.second; j++) {
                file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << label(i, j);
            }
        }
        file << '\n';
    }
    std::cout << std::endl;
    file.close();
}

std::pair<std::vector<Matrix>, std::vector<Matrix>> load_binary_testcase(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    std::vector<Matrix> x, y;
    int data_size;
    std::pair<int, int> input_shape;
    std::pair<int, int> label_shape;
    file.read(reinterpret_cast<char *>(&data_size), sizeof(int));
    file.read(reinterpret_cast<char *>(&input_shape.first), sizeof(int));
    file.read(reinterpret_cast<char *>(&input_shape.second), sizeof(int));
    file.read(reinterpret_cast<char *>(&label_shape.first), sizeof(int));
    file.read(reinterpret_cast<char *>(&label_shape.second), sizeof(int));
    for (int i = 0; i < data_size; i++) {
        std::cout << "\r[Load Dataset] "
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(6) << 100.0 * (i + 1) / data_size << "% "
                  << std::right << std::setw(8) << i + 1 << "/"
                  << std::left << std::setw(8) << data_size << std::flush;
        Matrix input(input_shape.first, input_shape.second);
        Matrix label(label_shape.first, label_shape.second);
        for (int j = 0; j < input_shape.first; j++) {
            for (int k = 0; k < input_shape.second; k++) {
                file.read(reinterpret_cast<char *>(&input(j, k)), sizeof(double));
            }
        }
        for (int j = 0; j < label_shape.first; j++) {
            for (int k = 0; k < label_shape.second; k++) {
                file.read(reinterpret_cast<char *>(&label(j, k)), sizeof(double));
            }
        }
        x.push_back(input);
        y.push_back(label);
    }
    std::cout << std::endl;
    return {x, y};
}

void save_binary_testcase(const std::string &filename, std::vector<Matrix> &x, std::vector<Matrix> &y) {
    if (x.size() != y.size()) {
        std::cerr << "Input and label size mismatch" << std::endl;
        exit(1);
    }
    std::ofstream file(filename, std::ios::binary);
    int data_size = int(x.size());
    std::pair<int, int> input_shape = x.front().shape();
    std::pair<int, int> label_shape = y.front().shape();
    file.write(reinterpret_cast<const char *>(&data_size), sizeof(int));
    file.write(reinterpret_cast<const char *>(&input_shape.first), sizeof(int));
    file.write(reinterpret_cast<const char *>(&input_shape.second), sizeof(int));
    file.write(reinterpret_cast<const char *>(&label_shape.first), sizeof(int));
    file.write(reinterpret_cast<const char *>(&label_shape.second), sizeof(int));
    for (int k = 0; k < data_size; k++) {
        std::cout << "\r[Save Dataset] "
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(6) << 100.0 * (k + 1) / data_size << "% "
                  << std::right << std::setw(8) << k + 1 << "/"
                  << std::left << std::setw(8) << data_size << std::flush;
        auto &input = x[k];
        auto &label = y[k];
        for (int i = 0; i < input_shape.first; i++) {
            for (int j = 0; j < input_shape.second; j++) {
                file.write(reinterpret_cast<const char *>(&input(i, j)), sizeof(double));
            }
        }
        for (int i = 0; i < label_shape.first; i++) {
            for (int j = 0; j < label_shape.second; j++) {
                file.write(reinterpret_cast<const char *>(&label(i, j)), sizeof(double));
            }
        }
    }
    std::cout << std::endl;
    file.close();
}