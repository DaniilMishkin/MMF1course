//
//  Header.h
//  LW01MishkinDD
//
//  Created by Даниил Мишкин on 28/02/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

namespace ArrayExtension{
    typedef int(*Key)(int, int, int);
    
    
    int* allocateMemory(int n);
    
    double* allocateMemoryDouble(int n);
    
    void inputArray(int * array, int n);
    
    void inputArray(double * array, int n);
    
    int inputNumber();
    
    int getPalindrome(int source);
    
    void makeUnique(int* array, int n, int& m);
    
    void inputNewArray(int* array, int* arrayNew, int n, int& m);
    
    void randomArray(int * array, int size);
    
    void displayArray(int * array, int n);
    
    int differenceOfRemainders(int number, int a, int b);
        
    void mergeSort(int* array, int n, Key key);
    
    void merge(int* array, int* left, int* right, int p, int q, Key key);
}


