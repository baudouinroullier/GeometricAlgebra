cmake_minimum_required(VERSION 3.17)

set(LIB_NAME "GeometricAlgebra")
project(${LIB_NAME} CXX)

add_library(${LIB_NAME}
    include/GeometricAlgebra/Maths.h src/Maths.cpp
    include/GeometricAlgebra/Vector.h src/Vector.cpp
    include/GeometricAlgebra/Multivector.h src/Multivector.cpp
)
set_target_properties(${LIB_NAME} PROPERTIES CXX_STANDARD 20 LINKER_LANGUAGE CXX)

target_include_directories(${LIB_NAME} PRIVATE "include/GeometricAlgebra")
