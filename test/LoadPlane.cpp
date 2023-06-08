//
// Created by ChrisKim on 2023/6/8.
//

#include "LoadPlane.h"

std::vector<std::pair<Matrix, Matrix>> circle_type(int size)
{
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::normal_distribution<double> distribution(0, 1);

    std::vector<std::pair<Matrix, Matrix>> data;

    // inner circle
    for (int i = 0; i < size / 2; i++)
    {
        double degree = 2.0 * i / size * 2 * M_PI;
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
        double degree = 2.0 * i / size * 2 * M_PI;
        double x = 4 * cos(degree) + 0.5 * distribution(generator);
        double y = 4 * sin(degree) + 0.5 * distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = x;
        dot[1][0] = y;
        label[0][0] = -1;
        data.emplace_back(dot, label);
    }
    return data;
}

std::vector<std::pair<Matrix, Matrix>> cluster_type(int size)
{
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::normal_distribution<double> distribution(0, 1);

    std::vector<std::pair<Matrix, Matrix>> data;

    // cluster 1
    for (int i = 0; i < size / 2; i++)
    {
        double x = distribution(generator);
        double y = distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = x;
        dot[1][0] = y;
        label[0][0] = 1;
        data.emplace_back(dot, label);
    }

    // cluster 2
    for (int i = 0; i < size / 2; i++)
    {
        double x = 4 + distribution(generator);
        double y = 4 + distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = x;
        dot[1][0] = y;
        label[0][0] = -1;
        data.emplace_back(dot, label);
    }

    return data;
}

std::vector<std::pair<Matrix, Matrix>> window_type(int size)
{
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::uniform_real_distribution<double> distribution(-1, 1);

    std::vector<std::pair<Matrix, Matrix>> data;

    for (int i = 0; i < size; i++)
    {
        double x = distribution(generator);
        double y = distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = x;
        dot[1][0] = y;
        if (x * y >= 0)
        {
            label[0][0] = 1;
        }
        else
        {
            label[0][0] = -1;
        }
        data.emplace_back(dot, label);
    }

    return data;
}

std::vector<std::pair<Matrix, Matrix>> whirlpool_type(int size)
{
    // random generator
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto timestamp = now_sec.time_since_epoch().count();
    std::default_random_engine generator(timestamp);
    std::normal_distribution<double> distribution(0, 0.4);

    std::vector<std::pair<Matrix, Matrix>> data;

    // type 1
    for (int i = 0; i < size / 2; i++)
    {
        double degree = 4.0 * i / size * 2 * M_PI;
        double x = degree * cos(degree) + distribution(generator);
        double y = degree * sin(degree) + distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = x;
        dot[1][0] = y;
        label[0][0] = 1;
        data.emplace_back(dot, label);
    }

    // type -1
    for (int i = 0; i < size / 2; i++)
    {
        double degree = 4.0 * i / size * 2 * M_PI;
        double x = degree * cos(degree + 2 * M_PI) + distribution(generator);
        double y = degree * sin(degree + 2 * M_PI) + distribution(generator);
        Matrix dot(2, 1);
        Matrix label(1, 1);
        dot[0][0] = -x;
        dot[1][0] = -y;
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
    else if (type == "cluster")
    {
        return cluster_type(size);
    }
    else if (type == "window")
    {
        return window_type(size);
    }
    else if (type == "whirlpool")
    {
        return whirlpool_type(size);
    }
    else
    {
        std::cerr << "Error: unknown type" << std::endl;
        exit(1);
    }
}
