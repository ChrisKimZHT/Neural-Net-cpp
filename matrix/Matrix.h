//
// Created by ChrisKim on 2023/6/5.
//

#ifndef ANN_MATRIX_H
#define ANN_MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
protected:
    int _height, _length;
    double **_data;

public:
    Matrix() = default;
    Matrix(int height, int length, double val = 0);
    Matrix(const Matrix &mat);
    ~Matrix();

    [[nodiscard]] int height() const;
    [[nodiscard]] int length() const;
    Matrix transpose();
    void print() const;

    Matrix operator+(const Matrix &mat);
    Matrix &operator+=(const Matrix &mat);

    Matrix operator-(const Matrix &mat);
    Matrix &operator-=(const Matrix &mat);

    Matrix operator*(const Matrix &mat);

    Matrix operator*(const double &val);
    Matrix &operator*=(const double &val);

    Matrix operator/(const double &val);
    Matrix &operator/=(const double &val);

    double *operator[](int h_idx);
    const double *operator[](int h_idx) const;
};


#endif //ANN_MATRIX_H
