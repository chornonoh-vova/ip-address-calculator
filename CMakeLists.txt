cmake_minimum_required(VERSION 3.1.0)

project(ip_calculator)


set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(${PROJECT_NAME} "main.cpp" "util/util.h" "calc/calculator.h" "calc/calculator.cpp")
