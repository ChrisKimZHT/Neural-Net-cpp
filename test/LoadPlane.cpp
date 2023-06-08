//
// Created by ChrisKim on 2023/6/8.
//

#include "LoadPlane.h"

std::vector<std::pair<Matrix, Matrix>> circle_type(int size)
{
    std::vector<std::pair<Matrix, Matrix>> data;
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::normal_distribution<double> distribution(0, 1);
    // inner circle
    for (int i = 0; i < size / 2; i++)
    {
        double degree = 1.0 * i / size * 2 * M_PI;
        double x = cos(degree) + 0.5 * distribution(generator);
        double y = sin(degree) + 0.5 * distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = x;
        dot[1][0] = y;
        label[0][0] = 1;
        data.emplace_back(dot, label);
    }
    // outer ring
    for (int i = 0; i < size / 2; i++)
    {
        double degree = 1.0 * i / size * 2 * M_PI;
        double x = 2 * cos(degree) + 0.5 * distribution(generator);
        double y = 2 * sin(degree) + 0.5 * distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = x;
        dot[1][0] = y;
        label[0][0] = -1;
        data.emplace_back(dot, label);
    }
    return data;
}

std::vector<std::pair<Matrix, Matrix>> load_plane(int size, const std::string &type)
{
    if (type == "circle")
    {
        return circle_type(size);
    }
    return {};
}
