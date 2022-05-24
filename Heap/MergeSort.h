//
// Created by bruce on 3/31/22.
//

#ifndef SORTING_ADVANCE_MERGESORT_H
#define SORTING_ADVANCE_MERGESORT_H

#include "InsertionSort.h"
#include <algorithm>
using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <typename T>
void __merge( T arr[], int l, int mid, int r ) {

    T aux[ r - l + 1 ];
    for ( int i = l; i <= r; i++ )
        aux[ i - l ] = arr[ i ];

    int i = l, j = mid + 1;
    for ( int k = l; k <= r; k++ ) {
        if ( i > mid ) {
            arr[ k ] = aux[ j - l ];
            j++;
        } else if ( j > r ) {
            arr[ k ] = aux[ i - l ];
            i++;
        } else if ( aux[ i - l ] < aux[ j - l ] ) {
            arr[ k ] = aux[ i - l ];
            i++;
        } else {
            arr[ k ] = aux[ j - l ];
            j++;
        }
    }
}

// 递归使用归并排序，对arr[l ... r]的范围进行排序
template <typename T>
void __mergeSort( T arr[], int l, int r ) {

    //    if(l >= r)
    //        return;
    if ( r - l <= 15 ) {
        insertionSort( arr, l, r );
        return;
    }

    int mid = ( l + r ) / 2; // 当l和r较大时可能会发生溢出错误
    __mergeSort( arr, l, mid );
    __mergeSort( arr, mid + 1, r );
    if ( arr[ mid ] > arr[ mid + 1 ] ) __merge( arr, l, mid, r );
}

template <typename T>
void mergeSort( T arr[], int n ) {

    __mergeSort( arr, 0, n - 1 );
}

template <typename T>
void mergeSortBU( T arr[], int n ) {

    for ( int size = 1; size <= n; size += size )
        for ( int i = 0; i + size < n; i += size + size )
            // 对 arr[i...i+size-1] 和 arr[i+size...i+2*size-1] 进行归并
            if ( arr[ i + size - 1 ] > arr[ i + size ] )
                __merge( arr, i, i + size - 1,
                         min( i + size + size - 1, n - 1 ) );
}

#endif // SORTING_ADVANCE_MERGESORT_H
