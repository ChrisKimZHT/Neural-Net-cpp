#include <vector>
#include "ANN.h"

int main() {
    std::ios::sync_with_stdio(false);

    Network network({
        new ConvolutionalLayer({28, 28}, {3, 3}),
        new ActivationLayer(new Sigmoid),
        new ConvolutionalLayer({26, 26}, {3, 3}),
        new ActivationLayer(new Sigmoid),
        new FlattenLayer,
        new FullyConnectedLayer(24 * 24, 100),
        new ActivationLayer(new Sigmoid),
        new FullyConnectedLayer(100, 10),
        new ActivationLayer(new Sigmoid)
    });
    auto [train_input, train_output] = load_binary_testcase("../mnist_train.bin");
    auto [test_input, test_output] = load_binary_testcase("../mnist_test.bin");

    network.train(train_input, train_output, new MeanSquaredError, 80, 0.1);
    network.evaluate(test_input, test_output, new MeanSquaredError, true);

    return 0;
}
