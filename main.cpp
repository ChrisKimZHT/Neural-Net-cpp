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
#include "utils/LoadPolynomial.h"

double f(double x)
{
    return 1.1 * x * x + 4.5 * x + 1.4;
}

int main()
{
    std::cout << "Define Model..." << std::endl;
    Sigmoid sigmoid;
    Linear linear;
    Model model = Model({
                                Layer(1, linear),
                                Layer(20, sigmoid),
                                Layer(1, linear),
                        });

    std::cout << "Compiling Model..." << std::endl;
    MeanSquaredError mse;
    CompiledModel cmodel = model.compile(1, 0.1, 1, mse);

    std::cout << "Loading Dataset..." << std::endl;
//    std::vector<std::pair<Matrix, Matrix>> train_data = load_MNIST(R"(C:\Users\ChrisKim\Documents\CLionProjects\ANN\utils\mnist_test.csv)");
    std::vector<std::pair<Matrix, Matrix>> train_data = load_polynomial(1000, f);

    std::cout << "Training..." << std::endl;
    cmodel.fit(train_data, 10);

    return 0;
}
