#include <iostream>
#include <vector>
#include <utility>
#include "activation/Linear.h"
#include "activation/Sigmoid.h"
#include "matrix/Matrix.h"
#include "loss/MeanSquaredError.h"
#include "ann/Layer.h"
#include "ann/Model.h"
#include "ann/CompiledModel.h"
#include "test/LoadPlane.h"
#include "test/TestCaseFile.h"

int main()
{
    std::cout << "Define Model..." << std::endl;
    Sigmoid sigmoid;
    Linear linear;
    Model model = Model({
                                Layer(20, sigmoid),
                                Layer(1, linear),
                        });

    std::cout << "Compiling Model..." << std::endl;
    MeanSquaredError mse;
    CompiledModel cmodel = model.compile(2, 0.01, 1, mse);

    std::cout << "Loading Dataset..." << std::endl;
    /*
    auto poly = [](double x) -> double
    {
        return 1.1 * x * x + 4.5 * x + 1.4;
    };
    std::vector<std::pair<Matrix, Matrix>> train_data = load_polynomial(1000, poly);
    std::vector<std::pair<Matrix, Matrix>> test_data = load_polynomial(100, poly);
    */
    std::vector<std::pair<Matrix, Matrix>> train_data = load_plane(1000, "circle");
    std::vector<std::pair<Matrix, Matrix>> test_data = load_plane(100, "circle");
    save_testcase("./circle_train.txt", train_data);

    std::cout << "Training..." << std::endl;
    cmodel.fit(train_data, 10);

    std::cout << "Evaluating..." << std::endl;
    cmodel.evaluate(test_data);

    return 0;
}
