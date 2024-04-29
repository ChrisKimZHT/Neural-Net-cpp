#include <vector>
#include "network/Network.h"
#include "layer/FullyConnectedLayer.h"
#include "layer/ActivationLayer.h"
#include "activation/sigmoid.h"
#include "loss/MeanSquaredError.h"
#include "test/TestCaseFile.h"
#include "layer/ConvolutionalLayer.h"
#include "layer/FlattenLayer.h"

int main() {
    std::ios::sync_with_stdio(false);

    Network network({
        new ConvolutionalLayer({28, 28}, {3, 3}),
        new ActivationLayer(new Sigmoid),
        new FlattenLayer,
        new FullyConnectedLayer(26 * 26, 100),
        new ActivationLayer(new Sigmoid),
        new FullyConnectedLayer(100, 10),
        new ActivationLayer(new Sigmoid)
    });

    auto [train_input, train_output] = load_testcase("../mnist_train.txt");
    auto [test_input, test_output] = load_testcase("../mnist_test.txt");

    network.train(train_input, train_output, new MeanSquaredError, 60, 0.1);
    network.evaluate(test_input, test_output, new MeanSquaredError, true);

    return 0;
}
