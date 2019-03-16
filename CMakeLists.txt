cmake_minimum_required(VERSION 2.8)
project(polish_calc)

include_directories("src_polish_calc/include/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -g")

set(SRC_LIST "src_polish_calc/src/main.cpp")

add_executable(${PROJECT_NAME} ${SRC_LIST})