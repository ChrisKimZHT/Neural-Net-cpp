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
    int _height, _length;
    double **_data;

public:
    Matrix();

    Matrix(int height, int length, double val = 0);

    Matrix(const Matrix &mat);

    ~Matrix();

    [[nodiscard]] int height() const;

    [[nodiscard]] int length() const;

    [[nodiscard]] std::pair<int, int> shape() const;

    Matrix transpose();

    void set(double val);

    void print() const;

    void randomize(double min = -1.0, double max = 1.0);

    void perform(double(*f)(double));

    Matrix &operator=(const Matrix &mat);

    Matrix operator+(const Matrix &mat) const;

    Matrix &operator+=(const Matrix &mat);

    Matrix operator-(const Matrix &mat) const;

    Matrix &operator-=(const Matrix &mat);

    Matrix operator*(const Matrix &mat) const;

    Matrix operator*(const double &val) const;

    Matrix &operator*=(const double &val);

    Matrix operator/(const double &val) const;

    Matrix &operator/=(const double &val);

    [[nodiscard]] Matrix hadamard(const Matrix &mat) const;

    double *operator[](int h_idx);

    const double *operator[](int h_idx) const;
};


#endif //ANN_MATRIX_H
