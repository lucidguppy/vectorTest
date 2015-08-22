cmake_minimum_required(VERSION 3.2)
project(vectorTest)

configure_file(process.py process.py COPYONLY)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(vectorTest ${SOURCE_FILES})
