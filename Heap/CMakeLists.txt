cmake_minimum_required(VERSION 3.21)
project(Heap)

set(CMAKE_CXX_STANDARD 11)

add_executable(Heap main.cpp Heap.h HeapSort.h QuickSort2Ways.h IndexMaxHeap.h)
