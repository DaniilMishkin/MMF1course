//
//  ArrayExtension.cpp
//  LW01MishkinDD
//
//  Created by Даниил Мишкин on 28/02/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#include "ArrayLibrary.h"
#include <iostream>
#include "cmath"

int* ArrayExtension::allocateMemory(int n)
{
    if (n <= 0)
    {
        //return nullptr;
        throw std::invalid_argument("Count of array elements can not be less or equal 0.");
    }
    
    int* array = new int[n];
    
    return array;
}

double* ArrayExtension::allocateMemoryDouble(int n)
{
    if (n <= 0)
    {
        //return nullptr;
        throw std::invalid_argument("Count of array elements can not be less or equal 0.");
    }
    
    double* array = new double[n];
    
    return array;
}

void ArrayExtension::inputArray(int * array, int n)
{
    if (array == nullptr)
    {
        throw std::invalid_argument("Array can not be null.");
    }
    
    if (n <= 0)
    {
        throw std::invalid_argument("Count of array elements can not be less or equal 0.");
    }
    
    for (int* p = array, i = 1; p < array + n; p++, i++)
    {
        std::cout << "a[" << i << "] = ";
        std::cin >> *p;
    }
}

void ArrayExtension::inputArray(double * array, int n)
{
    if (array == nullptr)
    {
        throw std::invalid_argument("Array can not be null.");
    }
    
    if (n <= 0)
    {
        throw std::invalid_argument("Count of array elements can not be less or equal 0.");
    }
    
    for (double* p = array, i = 1; p < array + n; p++, i++)
    {
        std::cout << "a[" << i << "] = ";
        std::cin >> *p;
    }
}

int ArrayExtension::inputNumber()
{
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    
    return n;
}

int ArrayExtension::getPalindrome(int source){
    int rem, result = 0;
    int n = source;
    int i = 0;
    
    while (source) {
        
        rem = source % 10;
        source /= 10;
        i++;
    }
    
    rem = 0;
    
    
    for (int j = i; j > 0; j--)
    {
        rem = n % 10;
        result = result + rem * pow(10, j - 1);
        n /= 10;
    }
    
    return result;
}
void ArrayExtension::makeUnique(int* array, int n, int& m){
    m = 0;
    
    for (int i = 0; i < n - 1 - m; i++) {
        for (int j = i + 1; j < n - m; j++) {
            
            if (array[i] == array[j]) {
                
                for (int k = j; k < n - m; k++) {
                    
                    array[k] = array[k + 1];
                }
                
                i--;
                m++;
            }
        }
        
    }
    
}

void ArrayExtension::inputNewArray(int* array, int* arrayNew, int n, int& m)
{
    m = 0;
    int k = 0;
    bool isMoved = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (array[i] == array[j] && isMoved==false) {
                
                arrayNew[k] = getPalindrome(array[i]);
                isMoved = true;
                k++;
                m++;
            }
        }
    }
}


void ArrayExtension::displayArray(int * array, int n){
    if (array == nullptr) {
        throw std::invalid_argument("Array can not be null.");
    }
    
    if (n <= 0) {
        throw std::invalid_argument("Count of array elements can not be less or equal 0.");
    }
    
    for (int* p = array; p < array + n; p++) {
        std::cout << *p << " ";
    }
    
    std::cout << std::endl;
}

int ArrayExtension::differenceOfRemainders(int number, int a, int b){
    int remA, remB, dif;
    
    remA = number / a;
    remB = number / b;
    
    if (remA > remB) {
        dif = remA - remB;
    } else {
        dif = remB - remA;
    }
    
    return dif;
}

void ArrayExtension::mergeSort(int* array, int n, Key key) {
    if (n > 1) {
        int p = n / 2 + n % 2;
        int q = n / 2;
        
        int* left = allocateMemory(p);
        int* right = allocateMemory(q);
        
        for (int i = 0; i < p; i++) {
            left[i] = array[i];
        }
        for (int j = 0; j < q; j++) {
            right[j] = array[p + j];
        }
        mergeSort(left, p, key);
        mergeSort(right, q, key);
        merge(array, left, right, p, q, key);
    } else {
        return;
    }
}

void ArrayExtension::merge(int* array, int* left, int* right, int p, int q, Key key) {
    int j = 0, k = 0;
    
    for (int i = 0; i < p + q; i++) {
        if (j == p) {
            array[i] = right[k];
            k++;
        }
        else if (k == q) {
            
            array[i] = left[j];
            j++;
        } else if (Key(left[j]) < Key(right[k])) {
            
            *(array + i) = *(left + j);
            j++;
        } else {
            
            *(array + i) = *(right + k);
            k++;
        }
    }
}
