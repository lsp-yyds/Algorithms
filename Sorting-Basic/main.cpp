#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"

using namespace std;

int main() {

    int n = 10000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    //int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    //int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    int arr5[10] = {10,9,8,7,6,5,4,3,2,1};

    /*insertionSort(arr, n);
    SortTestHelper::printArray(arr, n);*/
    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort3, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort2, arr4, n);
    //SortTestHelper::testSort("Shell Sort", shellSort, arr5, n);
    shellSort(arr5, 10);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    //delete[] arr5;

    return 0;
}
