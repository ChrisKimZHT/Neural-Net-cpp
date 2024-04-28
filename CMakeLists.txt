cmake_minimum_required(VERSION 3.25)
project(ANN)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ANN
        main.cpp
        matrix/Matrix.cpp
        matrix/Matrix.h
        layer/Layer.cpp
        layer/Layer.h
        layer/Layer.h
        layer/FullyConnectedLayer.cpp
        layer/FullyConnectedLayer.h
        layer/ActivationLayer.cpp
        layer/ActivationLayer.h
        activation/ActivationFunction.cpp
        activation/ActivationFunction.h
        activation/Sigmoid.cpp
        activation/Sigmoid.h
        test/LoadPolynomial.cpp
        test/LoadPolynomial.h
        test/LoadPlane.cpp
        test/LoadPlane.h
        test/TestCaseFile.cpp
        test/TestCaseFile.h
        test/SavePlaneMesh.cpp
        test/SavePlaneMesh.h
        network/Network.cpp
        network/Network.h
        loss/LossFunction.cpp
        loss/LossFunction.h
        loss/MeanSquaredError.cpp
        loss/MeanSquaredError.h
)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")