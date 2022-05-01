//
// Created by bruce on 2/28/22.
//

#ifndef SORTING_BASIC_SELECTIONSORT_H
#define SORTING_BASIC_SELECTIONSORT_H

template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {

        // 寻找[i，n)区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(arr[i], arr[minIndex]);
    }
}

/*template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                swap(arr[j], arr[minIndex]);
        }
    }
}*/

#endif //SORTING_BASIC_SELECTIONSORT_H
