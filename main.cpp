#include <iostream>
#include "activation/Sigmoid.h"
#include "activation/ReLU.h"
#include "activation/Tanh.h"
#include "matrix/Matrix.h"
#include "loss/MeanSquaredError.h"
#include "ann/Layer.h"
#include "ann/Model.h"
#include "ann/CompiledModel.h"

int main()
{
//    std::cout << Sigmoid().f(1) << std::endl;
//    std::cout << ReLU().f(1) << std::endl;
//    std::cout << Tanh().f(1) << std::endl;
//
//    Matrix a(2, 3, 2);
//    Matrix b(3, 2);
//    b[0][0] = 4;
//    b[1][1] = 3;
//    b[2][1] = 2;
//    // 2 2 2     4 0
//    // 2 2 2  *  0 3
//    //           0 2
//    Matrix c = a * b;
//    c.print();
//
    Sigmoid sigmoid;
    ReLU relu;
    Tanh tanh;
//    Layer layer = Layer(3, sigmoid);
//    std::cout << layer.activation_function.f(-1) << std::endl;

    Model model = Model({
                                Layer(10, tanh),
                                Layer(100, sigmoid),
                                Layer(10, relu),
                        });

    MeanSquaredError mse;
    CompiledModel cmodel = model.compile(10, 0.1, 1, mse);

    Matrix input(10, 1);
    Matrix output = cmodel.predict(input);
    output.print();

    return 0;
}
