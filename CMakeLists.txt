cmake_minimum_required(VERSION 3.25)
project(ANN)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ANN
        ANN.h
        main.cpp

        matrix/Matrix.cpp
        matrix/Matrix.h

        network/Network.cpp
        network/Network.h

        layer/Layer.cpp
        layer/Layer.h
        layer/Layer.h
        layer/FullyConnectedLayer.cpp
        layer/FullyConnectedLayer.h
        layer/ActivationLayer.cpp
        layer/ActivationLayer.h
        layer/ConvolutionalLayer.cpp
        layer/ConvolutionalLayer.h

        loss/LossFunction.cpp
        loss/LossFunction.h
        loss/MeanSquaredError.cpp
        loss/MeanSquaredError.h

        activation/ActivationFunction.cpp
        activation/ActivationFunction.h
        activation/Sigmoid.cpp
        activation/Sigmoid.h
        activation/Tanh.cpp
        activation/Tanh.h
        activation/ReLu.cpp
        activation/ReLu.h

        test/LoadPolynomial.cpp
        test/LoadPolynomial.h
        test/LoadPlane.cpp
        test/LoadPlane.h
        test/TestCaseFile.cpp
        test/TestCaseFile.h
        test/SavePlaneMesh.cpp
        test/SavePlaneMesh.h
        layer/FlattenLayer.cpp
        layer/FlattenLayer.h
)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

if (CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O3")
endif ()