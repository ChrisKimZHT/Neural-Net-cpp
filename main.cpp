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

int main() {
    std::cout << "Define Model..." << std::endl;
    Sigmoid sigmoid;
    MeanSquaredError mse;
    Network network(&mse);
    FullyConnectedLayer layer1(2, 10);
    network.add_layer(&layer1);
    FullyConnectedLayer layer2(10, 10);
    network.add_layer(&layer2);
    FullyConnectedLayer layer3(10, 1);
    network.add_layer(&layer3);
    std::cout << "Loading Dataset..." << std::endl;

    std::vector<std::pair<Matrix, Matrix>> train_data = load_plane(1000, "whirlpool");

    std::vector<Matrix> train_input;
    std::vector<Matrix> train_output;

    for (auto &data: train_data) {
        train_input.push_back(data.first);
        train_output.push_back(data.second);
    }

    std::cout << "Training..." << std::endl;
    network.train(train_input, train_output, 1000, 0.01);

    std::cout << "Saving..." << std::endl;
    save_testcase("./train.txt", train_data);
    save_plane_mesh(-15, 15, 0.5,
                    -15, 15, 0.5,
                    network, "./mesh.txt");
    return 0;
}
