//
// Created by ChrisKim on 24-4-29.
//

#include "ConvolutionalLayer.h"

ConvolutionalLayer::ConvolutionalLayer(std::tuple<int, int> input_shape, std::tuple<int, int> filter_shape) {
    auto &[_input_h, _input_w] = input_shape;
    auto &[_filter_h, _filter_w] = filter_shape;
    input_h = _input_h;
    input_w = _input_w;
    filter_h = _filter_h;
    filter_w = _filter_w;
    output_h = input_h - filter_h + 1; // stride = 1
    output_w = input_w - filter_w + 1; // stride = 1

    weights = Matrix(filter_h, filter_w);
    weights.randomize();
    Matrix random = Matrix(1, 1);
    random.randomize();
    bias = random(0, 0);
}

Matrix ConvolutionalLayer::forward(const Matrix &input, bool is_eval) {
    this->input = input;
    Matrix output = input.convolution(weights);
    output += bias;
    return output;
}

Matrix ConvolutionalLayer::backward(const Matrix &d_output, double learning_rate) {
    Matrix d_input = d_output.convolution(weights.transpose(), false);
    Matrix d_filters = input.convolution(d_output.transpose(), true);
    double d_bias = d_output.sum();

    weights -= d_filters * learning_rate;
    bias -= d_bias * learning_rate;

    return d_input;
}


