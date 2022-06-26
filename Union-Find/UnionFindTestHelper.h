//
// Created by bruce on 6/22/22.
//

#ifndef UNION_FIND_UNIONFINDTESTHELPER_H
#define UNION_FIND_UNIONFINDTESTHELPER_H

#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include <ctime>
#include <iostream>

using namespace std;

namespace UnionFindTestHelper {
    void testUF1( int n ) {
        srand( time( NULL ) );
        UF1::UnionFind uf = UF1::UnionFind( n );

        time_t startTime = clock();

        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements( a, b );
        }
        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected( a, b );
        }
        time_t endTime = clock();
        cout << "UF1, " << 2 * n << " ops, "
             << double( endTime - startTime ) / CLOCKS_PER_SEC << endl;
    }

    void testUF2( int n ) {
        srand( time( NULL ) );
        UF2::UnionFind uf = UF2::UnionFind( n );

        time_t startTime = clock();

        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements( a, b );
        }
        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected( a, b );
        }
        time_t endTime = clock();
        cout << "UF2, " << 2 * n << " ops, "
             << double( endTime - startTime ) / CLOCKS_PER_SEC << endl;
    }

    void testUF3( int n ) {
        srand( time( NULL ) );
        UF3::UnionFind uf = UF3::UnionFind( n );

        time_t startTime = clock();

        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements( a, b );
        }
        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected( a, b );
        }
        time_t endTime = clock();
        cout << "UF3, " << 2 * n << " ops, "
             << double( endTime - startTime ) / CLOCKS_PER_SEC << endl;
    }

    void testUF4( int n ) {
        srand( time( NULL ) );
        UF4::UnionFind uf = UF4::UnionFind( n );

        time_t startTime = clock();

        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements( a, b );
        }
        for ( int i = 0; i < n; i++ ) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected( a, b );
        }
        time_t endTime = clock();
        cout << "UF4, " << 2 * n << " ops, "
             << double( endTime - startTime ) / CLOCKS_PER_SEC << endl;
    }
} // namespace UnionFindTestHelper

#endif // UNION_FIND_UNIONFINDTESTHELPER_H
