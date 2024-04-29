//
// Created by ChrisKim on 2023/6/5.
//

#ifndef ANN_MATRIX_H
#define ANN_MATRIX_H

#include <iostream>
#include <vector>
#include <utility>
#include <random>

class Matrix {
protected:
    int _row{}, _col{};
    std::vector<double> _data;

public:
    Matrix();

    Matrix(int row, int col, double val = 0);

    Matrix(const Matrix &mat);

    explicit Matrix(const std::vector<std::vector<double>> &data);

    void from_vector(const std::vector<std::vector<double>> &data);

    [[nodiscard]] int row() const;

    [[nodiscard]] int col() const;

    [[nodiscard]] std::pair<int, int> shape() const;

    [[nodiscard]] Matrix transpose() const;

    void set(double val);

    void print(int precision = 2) const;

    void randomize(double min = -0.5, double max = 0.5);

    void perform(double(*f)(double));

    Matrix &operator=(const Matrix &mat);

    Matrix operator+(const Matrix &mat) const;

    Matrix &operator+=(const Matrix &mat);

    Matrix operator+(double x) const;

    Matrix &operator+=(double x);

    Matrix operator-(const Matrix &mat) const;

    Matrix &operator-=(const Matrix &mat);

    Matrix operator-(double x) const;

    Matrix &operator-=(double x);

    Matrix operator*(const Matrix &mat) const;

    Matrix operator*(const double &val) const;

    Matrix &operator*=(const double &val);

    Matrix operator/(const double &val) const;

    Matrix &operator/=(const double &val);

    double operator()(int r, int c) const;

    double &operator()(int r, int c);

    [[nodiscard]] Matrix hadamard(const Matrix &mat) const;

    [[nodiscard]] Matrix convolution(const Matrix &mat, bool valid = true) const;

    [[nodiscard]] double max() const;

    [[nodiscard]] double min() const;

    [[nodiscard]] std::pair<int, int> argmax() const;

    [[nodiscard]] std::pair<int, int> argmin() const;

    [[nodiscard]] Matrix reshape(int row, int col) const;
};

Matrix operator*(const double &val, const Matrix &mat);

Matrix make_matrix(const std::vector<std::vector<double>> &data);

#endif //ANN_MATRIX_H
