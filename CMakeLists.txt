cmake_minimum_required(VERSION 3.25)
project(ANN)

set(CMAKE_CXX_STANDARD 17)

add_executable(ANN main.cpp activation/ActivationFunction.cpp activation/ActivationFunction.h activation/Sigmoid.cpp activation/Sigmoid.h activation/ReLU.cpp activation/ReLU.h activation/Tanh.cpp activation/Tanh.h matrix/Matrix.cpp matrix/Matrix.h ann/Layer.cpp ann/Layer.h ann/Model.cpp ann/Model.h loss/LossFunction.cpp loss/LossFunction.h loss/MeanSquaredError.cpp loss/MeanSquaredError.h ann/CompiledModel.cpp ann/CompiledModel.h activation/Linear.cpp activation/Linear.h test/LoadPolynomial.cpp test/LoadPolynomial.h test/LoadPlane.cpp test/LoadPlane.h test/TestCaseFile.cpp test/TestCaseFile.h test/SavePlaneMesh.cpp test/SavePlaneMesh.h)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")