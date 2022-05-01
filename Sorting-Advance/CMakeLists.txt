cmake_minimum_required(VERSION 3.21)
project(Sorting_Advance)

set(CMAKE_CXX_STANDARD 11)

add_executable(Sorting_Advance main.cpp SortTestHelper.h MergeSort.h InsertionSort.h QuickSort.h QuickSortDealWithIdenticalKeys.h)
