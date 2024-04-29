#include <vector>
#include "network/Network.h"
#include "layer/FullyConnectedLayer.h"
#include "layer/ActivationLayer.h"
#include "activation/tanh.h"
#include "loss/MeanSquaredError.h"
#include "test/LoadPlane.h"
#include "test/SavePlaneMesh.h"

int main() {
    Tanh tanh;

    MeanSquaredError mse;
    Network network({
        new FullyConnectedLayer(2, 20),
        new ActivationLayer(&tanh),
        new FullyConnectedLayer(20, 20),
        new ActivationLayer(&tanh),
        new FullyConnectedLayer(20, 1),
        new ActivationLayer(&tanh)
    });

    auto [train_input, train_output] = load_plane(1000, "circle");
    auto [test_input, test_output] = load_plane(500, "circle");

    network.train(train_input, train_output, &mse, 25, 0.001);

    network.evaluate(test_input, test_output, &mse);

    save_plane_mesh_with_data("../test.txt", "../mesh.txt", test_input, test_output, network);

    return 0;
}
