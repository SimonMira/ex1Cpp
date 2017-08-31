cmake_minimum_required(VERSION 3.8)
project(ex1Cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ConvexHull.cpp ConvexHull.h Point.cpp Point.h PointSet.cpp PointSet.h)
add_executable(ex1Cpp ${SOURCE_FILES})