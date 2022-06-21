cmake_minimum_required(VERSION 3.21)
project(Binary_Search_Tree)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Binary_Search_Tree main.cpp BinarySearch.h FileOps.h SequenceST.h)
