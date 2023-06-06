#include <iostream>
#include "activation/Sigmoid.h"
#include "activation/ReLU.h"
#include "activation/Tanh.h"
#include "matrix/Matrix.h"
#include "matrix/Vector.h"
#include "loss/MeanSquaredError.h"
#include "ann/Layer.h"

int main()
{
    std::cout << Sigmoid().f(1) << std::endl;
    std::cout << ReLU().f(1) << std::endl;
    std::cout << Tanh().f(1) << std::endl;

    Matrix a(2, 3, 2);
    Matrix b(3, 2);
    b[0][0] = 4;
    b[1][1] = 3;
    b[2][1] = 2;
    // 2 2 2     4 0
    // 2 2 2  *  0 3
    //           0 2
    Matrix c = a * b;
    c.print();

    Vector d(3, 2);
    d.get(1) = 4;
    Matrix e = a * d;
    e.print();

    Vector x(4);
    x.get(0) = 1;
    x.get(1) = 2;
    x.get(2) = 3;
    x.get(3) = 4;
    Vector y(4);
    y.get(0) = 1;
    y.get(1) = 0;
    y.get(2) = 2;
    y.get(3) = 2;
    double ans = MeanSquaredError().f(x, y);
    Vector dans = MeanSquaredError().df(x, y);
    std::cout << ans << std::endl;
    dans.print();

    Sigmoid sigmoid;
    Layer layer = Layer(3, sigmoid);
    std::cout << layer.activation_function.f(-1) << std::endl;

    return 0;
}
