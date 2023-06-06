#include <iostream>
#include "activation/Sigmoid.h"
#include "activation/ReLU.h"
#include "activation/Tanh.h"
#include "matrix/Matrix.h"
#include "matrix/Vector.h"

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

    return 0;
}
