#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"
#include "SortTestHelper.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 1000000;

    std::cout << "Test for Random Array, size = " << n << ", random range [0, "
              << n << "]" << std::endl;
    int *arr1 = SortTestHelper::generateRandomArray( n, 0, n );
    int *arr2 = SortTestHelper::copyIntArray( arr1, n );
    int *arr3 = SortTestHelper::copyIntArray( arr1, n );
    int *arr4 = SortTestHelper::copyIntArray( arr1, n );
    int *arr5 = SortTestHelper::copyIntArray( arr1, n );
    int *arr6 = SortTestHelper::copyIntArray( arr1, n );
    int *arr7 = SortTestHelper::copyIntArray( arr1, n );

    SortTestHelper::testSort( "Merge Sort", mergeSort, arr1, n );
    SortTestHelper::testSort( "Quick Sort", quickSort, arr2, n );
    SortTestHelper::testSort( "Quick Sort 2 Ways", quickSort2, arr3, n );
    SortTestHelper::testSort( "Quick Sort 3 Ways", quickSort3Ways, arr4, n );
    SortTestHelper::testSort( "Heap Sort 1", heapSort1, arr5, n );
    SortTestHelper::testSort( "Heap Sort 2", heapSort2, arr6, n );
    SortTestHelper::testSort( "Heap Sort 3", heapSort3, arr7, n );

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    std::cout << std::endl;

    int swapTimes = 10;
    std::cout << "Test for Random Nearly Ordered Array, size = " << n
              << ", swap time = " << swapTimes << std::endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray( n, swapTimes );
    arr2 = SortTestHelper::copyIntArray( arr1, n );
    arr3 = SortTestHelper::copyIntArray( arr1, n );
    arr4 = SortTestHelper::copyIntArray( arr1, n );
    arr5 = SortTestHelper::copyIntArray( arr1, n );
    arr6 = SortTestHelper::copyIntArray( arr1, n );
    arr7 = SortTestHelper::copyIntArray( arr1, n );

    SortTestHelper::testSort( "Merge Sort", mergeSort, arr1, n );
    SortTestHelper::testSort( "Quick Sort", quickSort, arr2, n );
    SortTestHelper::testSort( "Quick Sort 2 Ways", quickSort2, arr3, n );
    SortTestHelper::testSort( "Quick Sort 3 Ways", quickSort3Ways, arr4, n );
    SortTestHelper::testSort( "Heap Sort 1", heapSort1, arr5, n );
    SortTestHelper::testSort( "Heap Sort 2", heapSort2, arr6, n );
    SortTestHelper::testSort( "Heap Sort 3", heapSort3, arr7, n );

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    std::cout << std::endl;

    std::cout << "Test for Random Array, size = " << n
              << ", random range [0, 10]" << std::endl;
    arr1 = SortTestHelper::generateRandomArray( n, 0, 10 );
    arr2 = SortTestHelper::copyIntArray( arr1, n );
    arr3 = SortTestHelper::copyIntArray( arr1, n );
    arr4 = SortTestHelper::copyIntArray( arr1, n );
    arr5 = SortTestHelper::copyIntArray( arr1, n );
    arr6 = SortTestHelper::copyIntArray( arr1, n );
    arr7 = SortTestHelper::copyIntArray( arr1, n );

    SortTestHelper::testSort( "Merge Sort", mergeSort, arr1, n );
    SortTestHelper::testSort( "Quick Sort", quickSort, arr2, n );
    SortTestHelper::testSort( "Quick Sort 2 Ways", quickSort2, arr3, n );
    SortTestHelper::testSort( "Quick Sort 3 Ways", quickSort3Ways, arr4, n );
    SortTestHelper::testSort( "Heap Sort 1", heapSort1, arr5, n );
    SortTestHelper::testSort( "Heap Sort 2", heapSort2, arr6, n );
    SortTestHelper::testSort( "Heap Sort 3", heapSort3, arr7, n );

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    return 0;
}
