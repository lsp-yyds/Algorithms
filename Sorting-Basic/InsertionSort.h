//
// Created by bruce on 2/28/22.
//

#ifndef SORTING_BASIC_INSERTIONSORT_H
#define SORTING_BASIC_INSERTIONSORT_H

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
        }
    }
}


template<typename T>
void insertionSort2(T arr[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && arr[j-1] > arr[j]; j--)
            swap(arr[j-1], arr[j]);
    }
}

template<typename T>
void insertionSort3(T arr[], int n) {

    for (int i = 1; i < n; i++) {

        // 寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for(j = i; j > 0 && arr[j-1] > e; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;

    }
}

/*template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - i; j < n; j++) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i - 1], arr[i]);
                i--;
            }
        }
    }
}*/

#endif //SORTING_BASIC_INSERTIONSORT_H
