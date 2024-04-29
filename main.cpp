#include <vector>
#include "network/Network.h"
#include "layer/FullyConnectedLayer.h"
#include "layer/ActivationLayer.h"
#include "activation/tanh.h"
#include "loss/MeanSquaredError.h"
#include "test/TestCaseFile.h"

int main() {
    std::ios::sync_with_stdio(false);
    Tanh tanh;

    MeanSquaredError mse;
    Network network({
        new FullyConnectedLayer(28 * 28, 100),
        new ActivationLayer(&tanh),
        new FullyConnectedLayer(100, 50),
        new ActivationLayer(&tanh),
        new FullyConnectedLayer(50, 10),
        new ActivationLayer(&tanh)
    });

    auto [train_input, train_output] = load_testcase("../mnist_train.txt");
    auto [test_input, test_output] = load_testcase("../mnist_test.txt");

    network.train(train_input, train_output, &mse, 60, 0.1);
    network.evaluate(test_input, test_output, &mse, true);

    return 0;
}
