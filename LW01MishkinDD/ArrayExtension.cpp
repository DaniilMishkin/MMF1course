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

int ArrayExtension::getPalindrome(int source){
    int result, n;
    
    while (source) {
        result += (source % 10) * pow(10,n);
        source /= 10;
        n++;
    }
    return result;
}
int * ArrayExtension::makeUnique(int* array, int & size){
    int newSize;
    bool isUniq;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                isUniq = false;
                break;
            } else {
                isUniq = true;
            }
        }
            
        if (isUniq == true) {
            array[newSize] = array[i];
            newSize++;
        }
    }
    
    int * resultArray = new int[newSize + 1];
    
    for (int i = 0; i < newSize + 1; i++){
        resultArray[i] = array[i];
    }
    
    return resultArray;
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

void ArrayExtension::sort(int* array, int n, int a, int b){
    bool swapped = true;
    
    while (swapped) {
        swapped = false;
        
        for (int i = 0; i < n - 1; i++) {
            if (differenceOfRemainders(array[i], a, b) < differenceOfRemainders(array[i + 1], a, b)) {
                std::swap(array[i], array[i + 1]);
                
                swapped = true;
            }
        }
    }
}
