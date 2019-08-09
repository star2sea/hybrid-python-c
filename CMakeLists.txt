cmake_minimum_required(VERSION 3.0)
project(hybrid)

set(CMAKE_BUILD_TYPE "RelWithDebInfo")

include_directories("C:/Python27/include")

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories("C:/Python27/libs")

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_library(hybrid SHARED src/hybrid.cpp src/utils.cpp)
