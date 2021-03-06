//
// Created by bruce on 5/25/22.
//

#ifndef HEAP_QUICKSORT2WAYS_H
#define HEAP_QUICKSORT2WAYS_H

#include "InsertionSort.h"
#include <cstdlib>
#include <ctime>

template <typename T>
int __partition2( T arr[], int l, int r ) {

    swap( arr[ l ], arr[ rand() % ( r - l + 1 ) + l ] );
    T v = arr[ l ];

    // arr[l+1...i] <= v; arr(j...r] >= v
    int i = l + 1, j = r;
    while ( true ) {
        while ( i <= r && arr[ i ] < v )
            i++;
        while ( j >= l + 1 && arr[ j ] > v )
            j--;
        if ( i > j ) break;
        swap( arr[ i ], arr[ j ] );
        i++;
        j--;
    }

    swap( arr[ l ], arr[ j ] );

    return j;
}

template <typename T>
void __quickSort2( T arr[], int l, int r ) {
    if ( r - l <= 15 ) {
        insertionSort( arr, l, r );
        return;
    }

    int p = __partition2( arr, l, r );
    __quickSort2( arr, l, p - 1 );
    __quickSort2( arr, p + 1, r );
}

template <typename T>
void quickSort2( T arr[], int n ) {
    srand( time( NULL ) );
    __quickSort2( arr, 0, n - 1 );
}

#endif // HEAP_QUICKSORT2WAYS_H
