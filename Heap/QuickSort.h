//
// Created by bruce on 4/10/22.
//

#ifndef SORTING_ADVANCE_QUICKSORT_H
#define SORTING_ADVANCE_QUICKSORT_H

#include "InsertionSort.h"
#include <cstdlib>
#include <ctime>

template <typename T>
int __partition( T arr[], int l, int r ) {

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
void __quickSort( T arr[], int l, int r ) {
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
