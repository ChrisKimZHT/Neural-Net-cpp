//
// Created by ChrisKim on 2023/6/5.
//

#include <iomanip>
#include <algorithm>
#include "Matrix.h"

Matrix::Matrix() {
    _row = 1;
    _col = 1;
    _data = {0};
}

Matrix::Matrix(int row, int col, double val)
        : _row(row), _col(col) {
    if (row <= 0 || col <= 0) {
        std::cerr << "Matrix size must be positive." << std::endl;
        exit(1);
    }
    _data.resize(row * col, val);
}

Matrix::Matrix(const Matrix &mat)
        : _row(mat._row), _col(mat._col) {
    _data.assign(mat._data.begin(), mat._data.end());
}

Matrix::Matrix(const std::vector<std::vector<double>> &data) {
    this->from_vector(data);
}

void Matrix::from_vector(const std::vector<std::vector<double>> &data) {
    _row = int(data.size());
    _col = int(data[0].size());
    _data.resize(_row * _col);
    for (int i = 0; i < _row; i++) {
        if (int(data[i].size()) != _col) {
            std::cerr << "Invalid matrix data: " << i << "th row has different size." << std::endl;
            exit(1);
        }
    }
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            this->operator()(i, j) = data[i][j];
        }
    }
}

int Matrix::row() const {
    return _row;
}

int Matrix::col() const {
    return _col;
}

std::pair<int, int> Matrix::shape() const {
    return {_row, _col};
}

Matrix Matrix::transpose() const {
    Matrix res;
    res._row = _col;
    res._col = _row;
    res._data.assign(_data.begin(), _data.end());
    return res;
}

void Matrix::set(double val) {
    _data.assign(_data.size(), val);
}

void Matrix::print(int precision) const {
    std::cout << "[\n";
    for (int i = 0; i < _row; i++) {
        std::cout << "  [";
        for (int j = 0; j < _col; j++) {
            if (j)
                std::cout << ", ";
            std::cout << std::fixed << std::setprecision(precision) << this->operator()(i, j);
        }
        std::cout << "]\n";
    }
    std::cout << "]" << std::endl;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this == &mat)
        return *this;
    if (_row != mat._row || _col != mat._col) {
        _row = mat._row;
        _col = mat._col;
        _data.resize(_row * _col);
    }
    _data.assign(mat._data.begin(), mat._data.end());
    return *this;
}

Matrix Matrix::operator+(const Matrix &mat) const {
    Matrix res(*this);
    res += mat;
    return res;
}

Matrix &Matrix::operator+=(const Matrix &mat) {
    if (_row != mat._row || _col != mat._col) {
        std::cerr << "Matrix size not match: can't perform addition between "
                  << "(" << _row << ", " << _col << ") and "
                  << "(" << mat._row << ", " << mat._col << ")" << std::endl;
        exit(1);
    }
    for (int i = 0; i < _data.size(); i++) {
        _data[i] += mat._data[i];
    }
    return *this;
}

Matrix Matrix::operator+(double x) const {
    Matrix res(*this);
    res += x;
    return res;
}

Matrix &Matrix::operator+=(double x) {
    for (double &i: _data) {
        i += x;
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &mat) const {
    Matrix res(*this);
    res -= mat;
    return res;
}

Matrix &Matrix::operator-=(const Matrix &mat) {
    if (_row != mat._row || _col != mat._col) {
        std::cerr << "Matrix size not match: can't perform subtraction between "
                  << "(" << _row << ", " << _col << ") and "
                  << "(" << mat._row << ", " << mat._col << ")" << std::endl;
        exit(1);
    }
    for (int i = 0; i < _data.size(); i++) {
        _data[i] -= mat._data[i];
    }
    return *this;
}

Matrix Matrix::operator-(double x) const {
    return *this + (-x);
}

Matrix &Matrix::operator-=(double x) {
    return *this += -x;
}

Matrix Matrix::operator*(const Matrix &mat) const {
    if (_col != mat._row) {
        std::cerr << "Matrix size not match: can't perform matrix multiplication between "
                  << "(" << _row << ", " << _col << ") and "
                  << "(" << mat._row << ", " << mat._col << ")" << std::endl;
        exit(1);
    }
    Matrix res(_row, mat._col);
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < mat._col; j++) {
            for (int k = 0; k < _col; k++) {
                res(i, j) += this->operator()(i, k) * mat(k, j);
            }
        }
    }
    return res;
}

Matrix Matrix::operator*(const double &val) const {
    Matrix res(*this);
    res *= val;
    return res;
}

Matrix &Matrix::operator*=(const double &val) {
    for (double &i: _data) {
        i *= val;
    }
    return *this;
}

Matrix Matrix::operator/(const double &val) const {
    Matrix res(*this);
    res /= val;
    return res;
}

Matrix &Matrix::operator/=(const double &val) {
    for (double &i: _data) {
        i /= val;
    }
    return *this;
}

void Matrix::randomize(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);
    for (double &i: _data) {
        i = dis(gen);
    }
}

void Matrix::perform(double (*f)(double)) {
    for (double &i: _data) {
        i = f(i);
    }
}

Matrix Matrix::hadamard(const Matrix &mat) const {
    if (_row != mat._row || _col != mat._col) {
        std::cerr << "Matrix size not match: can't perform hadamard product between "
                  << "(" << _row << ", " << _col << ") and "
                  << "(" << mat._row << ", " << mat._col << ")" << std::endl;
        exit(1);
    }
    Matrix res(*this);
    for (int i = 0; i < _data.size(); i++) {
        res._data[i] *= mat._data[i];
    }
    return res;
}

Matrix Matrix::convolution(const Matrix &mat, bool valid) const {
    // correlation between this matrix and mat matrix
    // valid: if true, return valid convolution, else return full convolution
    int row = valid ? _row - mat._row + 1 : _row + mat._row - 1;
    int col = valid ? _col - mat._col + 1 : _col + mat._col - 1;
    Matrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // calculate convolution at (i, j)
            double sum = 0;
            for (int k = 0; k < mat._row; k++) {
                for (int l = 0; l < mat._col; l++) {
                    if (i + k >= 0 && i + k < 0 + _row && j + l >= 0 && j + l < 0 + _col) {
                        sum += this->operator()(i + k, j + l) * mat(k, l);
                    }
                }
            }
            res(i, j) = sum;
        }
    }
    return res;
}

double Matrix::max() const {
    return *std::max_element(_data.begin(), _data.end());
}

double Matrix::min() const {
    return *std::min_element(_data.begin(), _data.end());
}

double Matrix::sum() const {
    return std::accumulate(_data.begin(), _data.end(), 0.0);
}

std::pair<int, int> Matrix::argmax() const {
    int max_idx = int(std::max_element(_data.begin(), _data.end()) - _data.begin());
    return {max_idx / _col, max_idx % _col};
}

std::pair<int, int> Matrix::argmin() const {
    int min_idx = int(std::min_element(_data.begin(), _data.end()) - _data.begin());
    return {min_idx / _col, min_idx % _col};
}

Matrix Matrix::reshape(int row, int col) const {
    if (_row * _col != row * col) {
        std::cerr << "Matrix size not match: can't reshape "
                  << "(" << _row << ", " << _col << ") to "
                  << "(" << row << ", " << col << ")" << std::endl;
        exit(1);
    }
    Matrix res(*this);
    res._row = row;
    res._col = col;
    return res;
}

double Matrix::operator()(int r, int c) const {
    return _data[r * _col + c];
}

double &Matrix::operator()(int r, int c) {
    return _data[r * _col + c];
}

Matrix operator*(const double &val, const Matrix &mat) {
    return mat * val;
}

Matrix make_matrix(const std::vector<std::vector<double>> &data) {
    return Matrix(data);
}