//
//  main.cpp
//  LW01MishkinDD
//
//  Created by Даниил Мишкин on 28/02/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include "ArrayLibrary.h"

using namespace ArrayExtension;
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n = inputNumber();
    int* array = allocateMemory(n);
    
    cout << "Enter array" << endl;
    inputArray(array, n);
    displayArray(array, n);
    
    int m = 0;
    
    int *newArray = allocateMemory(n);
    inputNewArray(array, newArray, n, m);
    
    int a, b;
    cout << "a: ";
    a = inputNumber();
    cout << "b: ";
    b = inputNumber();
    
    mergeSort(array, n - m, differenceOfRemainders);
    cout << "Sorted array: ";
    displayArray(array, n - m);
    
    return 0;
}
