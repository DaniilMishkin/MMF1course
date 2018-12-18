//
//  ArrayLibrary.h
//  HWLibraries
//
//  Created by Даниил Мишкин on 18/12/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#ifndef ArrayLibrary_h
#define ArrayLibrary_h

#include <iostream>

using namespace std;

const int N = 100;

void getKeys(int[][N], int, int, int*);
void getValidRows(int[][N], int, int, int*, int&);
bool isValidRow(int*, int);
void sort(int[][N], int*, int, int*, int);
void swap(int left[], int right[], int n);

void swap(int left[], int right[], int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(left[i], right[i]);
    }
}

void getKeys(int matrix[][N], int n, int m, int* keys) {
    for (int i = 0; i < n; i++) {
        int prod = matrix[i][0];
        for (int j = 1; j < m; j++) {
            prod *= matrix[i][j];
        }
        keys[i] = prod;
    }
}

void getValidRows(int matrix[][N], int n, int m, int* rows, int& length) {
    length = 0;
    for (int i = 0; i < n; i += 2) {
        rows[length++] = i;
    }
}

bool isValidRow(int* array, int length) {
    return sum(array, length) >= 0;
}


void sort(int matrix[][N], int* keys, int m, int* rows, int length) {
    bool swapped = true;
    int i = 1;
    
    while (swapped) {
        swapped = false;
        
        for (int j = length - 1; j >= i; j--) {
            int current = rows[j];
            int next = rows[j - 1];
            if (keys[current] < keys[next]) {
                swap(matrix[current], matrix[next], m);
                swap(keys[next], keys[current]);
                swapped = true;
            }
        }
        
        i++;
    }
}

void columnsSwap(int matrix[N][N], int n, int m)
{
    int temp[N][N] = { { 0 } };
    int count = 0;
    while (count < m/2)
    {
        for (int i = 0, j = count, k = 0; i < n; i++, k++)
        {
            temp[k][0] = matrix[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            matrix[i][count] = matrix[i][m - 1 - count];
        }
        for (int i = 0, k = 0; i < n; i++, k++)
        {
            matrix[i][m - 1 - count] = temp[k][0];
        }
        count++;
    }
}

void rowsSwap(int matrix[N][N], int n, int m)
{
    int temp[N][N] = { { 0 } };
    int count = 0;
    while (count < n / 2)
    {
        for (int j = 0, i = count, k = 0; j < m; j++, k++)
        {
            temp[0][k] = matrix[i][j];
        }
        for (int j = 0; j < m; j++)
        {
            matrix[count][j] = matrix[n - 1 - count][j];
        }
        for (int j = 0, k = 0; j < m; j++, k++)
        {
            matrix[n - 1 - count][j] = temp[0][k];
        }
        count++;
    }
}

#endif /* ArrayLibrary_h */
