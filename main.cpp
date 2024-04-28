#include <iostream>
#include <vector>
#include <utility>
#include "activation/Sigmoid.h"
#include "matrix/Matrix.h"
#include "test/LoadPlane.h"
#include "test/TestCaseFile.h"
#include "test/SavePlaneMesh.h"
#include "network/Network.h"
#include "loss/MeanSquaredError.h"
#include "layer/FullyConnectedLayer.h"
#include "layer/ActivationLayer.h"

int main() {
    Sigmoid sigmoid;
    MeanSquaredError mse;
    Network network(&mse);
    FullyConnectedLayer layer1(2, 3);
    network.add_layer(&layer1);
    ActivationLayer activation1(3, &sigmoid);
    network.add_layer(&activation1);
    FullyConnectedLayer layer2(3, 1);
    network.add_layer(&layer2);
    ActivationLayer activation2(1, &sigmoid);
    network.add_layer(&activation2);

    std::vector<Matrix> train_input;
    std::vector<Matrix> train_output;
    Matrix a(2, 1), b(2, 1), c(2, 1), d(2, 1);
    a[0][0] = 0;
    a[1][0] = 0;
    b[0][0] = 0;
    b[1][0] = 1;
    c[0][0] = 1;
    c[1][0] = 0;
    d[0][0] = 1;
    d[1][0] = 1;
    train_input.push_back(a);
    train_input.push_back(b);
    train_input.push_back(c);
    train_input.push_back(d);
    Matrix a_out(1, 1), b_out(1, 1), c_out(1, 1), d_out(1, 1);
    a_out[0][0] = 0;
    b_out[0][0] = 1;
    c_out[0][0] = 1;
    d_out[0][0] = 0;
    train_output.push_back(a_out);
    train_output.push_back(b_out);
    train_output.push_back(c_out);
    train_output.push_back(d_out);

    network.train(train_input, train_output, 10000, 0.1);
    return 0;
}
