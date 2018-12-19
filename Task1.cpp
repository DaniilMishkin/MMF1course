//
//  Task1.cpp
//  ControlWork19.12.18
//
//  Created by Даниил Мишкин on 19/12/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//


#include <stdio.h>

#include <iostream>

#include <math.h>

const int N = 100;

using namespace std;

int nextSmallerThan(int);
void nextSmallerThanTests();

int main()
{
    nextSmallerThanTests();
}

int nextSmallerThan(int number){
    int digits[N] ={0};
    int i = 0;
    while (number) {
        digits[i] = number % 10;
        number /=10;
        i++;
    }
    if (i+1<2){
        return -1;
    }
    
    
    
    int j = 0, lengthOfNumber = i+1, smallNumber = 0;
    bool doesItExist = false;
    
    while (i != 0) {
        i--;
        if (digits[j] < digits[j+1] && digits[j] != 0) {
            i = digits[j];
            digits[j] = digits[j+1];
            digits[j+1] = i;
            doesItExist = true;
            i = 0;
        }
        j++;
    }
    
    if (doesItExist == true) {
        for (int i = 1; i <= lengthOfNumber; i++){
            smallNumber += digits[i-1]*pow(10, i);
        }
        return smallNumber / 10;
    } else {
        return -1;
    }
}

void nextSmallerThanTests()
{
    cout << (nextSmallerThan(21) == 12) << endl;
    cout << (nextSmallerThan(531) == 513) << endl;
    cout << (nextSmallerThan(2071) == 2017) << endl;
    cout << (nextSmallerThan(9) == -1) << endl;
    cout << (nextSmallerThan(111) == -1) << endl;
    cout << (nextSmallerThan(135) == -1) << endl;
    cout << (nextSmallerThan(2076) == 2067) << endl;
    cout << (nextSmallerThan(12354) == 12345) << endl;
    cout << (nextSmallerThan(22443) == 22434) << endl;
    cout << (nextSmallerThan(26676) == 26667) << endl;
    cout << (nextSmallerThan(6) == -1) << endl;
}
