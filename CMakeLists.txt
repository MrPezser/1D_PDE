cmake_minimum_required(VERSION 3.25)
project(1D_PDE)

set(CMAKE_CXX_STANDARD 17)

add_executable(1D_PDE main.cpp SpatialDiscretization.cpp SpatialDiscretization.h GridUtil.cpp GridUtil.h Equations.cpp Equations.h)
