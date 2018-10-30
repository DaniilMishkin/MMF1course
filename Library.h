//
//  main.cpp
//  31.10.2018
//
//  Created by Даниил Мишкин on 27/10/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include "math.h"

using namespace std;

long long  FibonacchiNumber (int number) {
    if (number == 0) {
        return 0;
    }
    if (number == 1){
        return 1;
        
    } else {
        return FibonacchiNumber(number-1)+FibonacchiNumber(number-2);
    }
    
}


int GetCountsOfDigits(long number) {
    int count = (number == 0) ? 1 : 0;
    while (number != 0) {
        count++;
        number /= 10;
    }
    return count;
}

void GetCountOfEveryDigit (long long number) {
    int digits[10] = {0,0,0,0,0,0,0,0,0,0};
    while (number != 0) {
        digits[number % 10]++;
        number /= 10;
    }
    for (int i=0; i<=9; i++) {
        cout << "Amount of '" << i << "' in this number = " << digits[i] << endl;
    }
}

void MaxMinDigitInicialization (long long number) {
    int max,min = number % 10;
    while (number != 0) {
        if (max < number % 10) {
            max = number%10;
        }
        if (min > number % 10) {
            min = number%10;
        }
        number /=10;
    }
    cout << "MIN digit is " << min << " and MAX digit is " << max <<endl;
}

bool IsItPrimeNumber(long long number){
    bool result = true;
    for (long long i = 2; i <= sqrt(number); i++)
    {
        if (!(number % i))
        {
            result = false;
            break;
        }
    }
    return result;
}

