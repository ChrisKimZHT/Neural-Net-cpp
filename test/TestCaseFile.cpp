//
// Created by ChrisKim on 2023/6/8.
//

#include "TestCaseFile.h"

std::vector<std::pair<Matrix, Matrix>> load_testcase(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<std::pair<Matrix, Matrix>> data;
    int data_size;
    std::pair<int, int> input_shape;
    std::pair<int, int> label_shape;
    file >> data_size
         >> input_shape.first >> input_shape.second
         >> label_shape.first >> label_shape.second;
    for (int i = 0; i < data_size; i++)
    {
        Matrix input(input_shape.first, input_shape.second);
        Matrix label(label_shape.first, label_shape.second);
        for (int j = 0; j < input_shape.first; j++)
        {
            for (int k = 0; k < input_shape.second; k++)
            {
                file >> input[j][k];
            }
        }
        for (int j = 0; j < label_shape.first; j++)
        {
            for (int k = 0; k < label_shape.second; k++)
            {
                file >> label[j][k];
            }
        }
        data.emplace_back(input, label);
    }
    return data;
}

void save_testcase(const std::string &filename, std::vector<std::pair<Matrix, Matrix>> &data)
{
    std::ofstream file(filename);
    int data_size = int(data.size());
    std::pair<int, int> input_shape = data.front().first.shape();
    std::pair<int, int> label_shape = data.front().second.shape();
    file << data_size << '\n'
         << input_shape.first << ' ' << input_shape.second << '\n'
         << label_shape.first << ' ' << label_shape.second << '\n';
    for (auto &[input, label]: data)
    {
        for (int i = 0; i < input_shape.first; i++)
        {
            for (int j = 0; j < input_shape.second; j++)
            {
                file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << input[i][j];
            }
        }
        for (int i = 0; i < label_shape.first; i++)
        {
            for (int j = 0; j < label_shape.second; j++)
            {
                file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << label[i][j];
            }
        }
        file << '\n';
    }
    file.close();
}