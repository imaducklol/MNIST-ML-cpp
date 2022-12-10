cmake_minimum_required(VERSION 3.24)
project(MNIST_ML_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(MNIST_ML_cpp main.cpp sfmlFuncs.h functions.h)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(MNIST_ML_cpp sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

