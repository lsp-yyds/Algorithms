//
// Created by bruce on 4/10/22.
//

#ifndef SORTING_ADVANCE_QUICKSORT_H
#define SORTING_ADVANCE_QUICKSORT_H

#include "InsertionSort.h"
#include <cstdlib>
#include <ctime>

// 对arr[l...r]部分进行partition操作
// 返回p,使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
template <typename T>
int __partition( T arr[], int l, int r ) {

    swap( arr[ l ], arr[ rand() % ( r - l + 1 ) + l ] );

    T v = arr[ l ];

    // arr[l+1...j] < v; arr[j+1...i) > v;
    int j = l;
    for ( int i = l + 1; i <= r; i++ ) {
        if ( arr[ i ] < v ) {
            swap( arr[ ++j ], arr[ i ] );
            // swap(arr[j+1], arr[i]);
            // j++;
        }
    }

    swap( arr[ l ], arr[ j ] );

    return j;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort( T arr[], int l, int r ) {

    //    if(l >= r)
    //        return;
    if ( r - l <= 15 ) {
        insertionSort( arr, l, r );
        return;
    }

    int p = __partition( arr, l, r );
    __quickSort( arr, l, p - 1 );
    __quickSort( arr, p + 1, r );
}

template <typename T>
void quickSort( T arr[], int n ) {

    srand( time( NULL ) );
    __quickSort( arr, 0, n - 1 );
}

#endif // SORTING_ADVANCE_QUICKSORT_H
