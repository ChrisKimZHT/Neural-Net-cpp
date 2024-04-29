//
// Created by ChrisKim on 24-4-29.
//

#ifndef ANN_CONVOLUTIONALLAYER_H
#define ANN_CONVOLUTIONALLAYER_H


#include "Layer.h"

struct ConvolutionalLayer : public Layer {
    int input_h, input_w, input_c; // input channel not implemented
    int filter_h, filter_w;
    int output_h, output_w, output_c; // output channel not implemented
    Matrix weights; // (filter_h, filter_w)
    double bias;

    Matrix input;

    ConvolutionalLayer(std::tuple<int, int> input_shape, std::tuple<int, int> filter_shape);

    Matrix forward(const Matrix &input) override;

    Matrix backward(const Matrix &d_output, double learning_rate) override;
};


#endif //ANN_CONVOLUTIONALLAYER_H
