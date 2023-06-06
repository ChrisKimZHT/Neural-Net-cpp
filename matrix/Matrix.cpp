//
// Created by ChrisKim on 2023/6/5.
//

#include "Matrix.h"

Matrix::Matrix()
{
    _height = 1;
    _length = 1;
    _data = new double *[1];
    _data[0] = new double[1];
    _data[0][0] = 0;
}

Matrix::Matrix(int height, int length, double val)
        : _height(height), _length(length)
{
    if (height <= 0 || length <= 0)
    {
        std::cout << "Matrix size must be positive." << std::endl;
        exit(1);
    }

    _data = new double *[height];
    for (int i = 0; i < height; i++)
    {
        _data[i] = new double[length];
    }

    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] = val;
        }
    }
}

Matrix::Matrix(const Matrix &mat)
        : _height(mat._height), _length(mat._length)
{
    _data = new double *[_height];
    for (int i = 0; i < _height; i++)
    {
        _data[i] = new double[_length];
    }

    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] = mat._data[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < _height; i++)
    {
        delete[] _data[i];
    }
    delete[] _data;
}

int Matrix::height() const
{
    return _height;
}

int Matrix::length() const
{
    return _length;
}

std::pair<int, int> Matrix::shape() const
{
    return {_height, _length};
}

Matrix Matrix::transpose()
{
    Matrix res(_length, _height);
    for (int i = 0; i < _length; i++)
    {
        for (int j = 0; j < _height; j++)
        {
            res._data[i][j] = _data[j][i];
        }
    }
    return res;
}

void Matrix::set(double val)
{
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] = val;
        }
    }
}

void Matrix::print() const
{
    std::cout << "[\n";
    for (int i = 0; i < _height; i++)
    {
        std::cout << "  [";
        for (int j = 0; j < _length; j++)
        {
            if (j)
                std::cout << ", ";
            std::cout << _data[i][j];
        }
        std::cout << "]\n";
    }
    std::cout << "]" << std::endl;
}

Matrix &Matrix::operator=(const Matrix &mat)
{
    if (this == &mat)
        return *this;
    if (_height != mat._height || _length != mat._length)
    {
        for (int i = 0; i < _height; i++)
        {
            delete[] _data[i];
        }
        delete[] _data;

        _height = mat._height;
        _length = mat._length;

        _data = new double *[_height];
        for (int i = 0; i < _height; i++)
        {
            _data[i] = new double[_length];
        }
    }
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] = mat._data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &mat)
{
    if (_height != mat._height || _length != mat._length)
    {
        std::cout << "Matrix size not match. (add)" << std::endl;
        exit(1);
    }
    Matrix res(_height, _length);
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            res._data[i][j] = _data[i][j] + mat._data[i][j];
        }
    }
    return res;
}

Matrix &Matrix::operator+=(const Matrix &mat)
{
    if (_height != mat._height || _length != mat._length)
    {
        std::cout << "Matrix size not match. (add)" << std::endl;
        exit(1);
    }
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] += mat._data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &mat)
{
    if (_height != mat._height || _length != mat._length)
    {
        std::cout << "Matrix size not match. (subtract)" << std::endl;
        exit(1);
    }
    Matrix res(_height, _length);
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            res._data[i][j] = _data[i][j] - mat._data[i][j];
        }
    }
    return res;
}

Matrix &Matrix::operator-=(const Matrix &mat)
{
    if (_height != mat._height || _length != mat._length)
    {
        std::cout << "Matrix size not match. (subtract)" << std::endl;
        exit(1);
    }
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] -= mat._data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix &mat)
{
    if (_length != mat._height)
    {
        std::cout << "Matrix size not match. (multiply)" << std::endl;
        exit(1);
    }
    Matrix res(_height, mat._length);
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < mat._length; j++)
        {
            res._data[i][j] = 0;
            for (int k = 0; k < _length; k++)
            {
                res._data[i][j] += _data[i][k] * mat._data[k][j];
            }
        }
    }
    return res;
}

Matrix Matrix::operator*(const double &val)
{
    Matrix res(_height, _length);
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            res._data[i][j] = _data[i][j] * val;
        }
    }
    return res;
}

Matrix &Matrix::operator*=(const double &val)
{
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] *= val;
        }
    }
    return *this;
}

Matrix Matrix::operator/(const double &val)
{
    Matrix res(_height, _length);
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            res._data[i][j] = _data[i][j] / val;
        }
    }
    return res;
}

Matrix &Matrix::operator/=(const double &val)
{
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _length; j++)
        {
            _data[i][j] /= val;
        }
    }
    return *this;
}

double *Matrix::operator[](int h_idx)
{
    return _data[h_idx];
}

const double *Matrix::operator[](int h_idx) const
{
    return _data[h_idx];
}







