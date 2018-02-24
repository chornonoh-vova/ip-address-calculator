cmake_minimum_required(VERSION 3.1.0)

project(ip-calculator)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(${PROJECT_NAME} "src/main.cpp" "src/util/util.h" "src/calc/calculator.h" "src/calc/calculator.cpp")
