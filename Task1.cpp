//
//  Task1.cpp
//  24.10.2018
//
//  Created by Даниил Мишкин on 27/10/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#include <stdio.h>
#include "Library.h"
#include "math.h"

using namespace std;

int FibonacchiNumber (long number);
int GetCountsOfDigits(long number);
void GetCountOfEveryDigit (long long number);
void MaxMinDigitInicialization (long long number);
bool IsItPrimeNumber(long long number);

int main () {
    char bottom = 'f';
    while (bottom == 'f' || bottom == 'F') {
        cout << "Enter your number: ";
        
        int number,digits;
        
        cin >> number;
        
        GetCountOfEveryDigit (number);
        
        MaxMinDigitInicialization(number);
        
        if (IsItPrimeNumber(number) == true ) {
            cout << "Your number is a prime number!" << endl;
        } else {
            cout << "Your number isn't a prime number!" << endl;
        }
        
        cout << "Enter amount of digits in fibonacchi number: ";
        cin >> digits;
        int i = -1;
        do {
            i++;
        } while (GetCountsOfDigits(FibonacchiNumber(i)) != digits);
        cout << "MIN fibonacchi number consists of  " << digits << " digits is " << FibonacchiNumber(i) << endl;
        
        do {
            i++;
        } while (GetCountsOfDigits(FibonacchiNumber(i)) !=(digits + 1));
        cout << "MAX fibonacchi number consists of  " << digits << " digits is " << FibonacchiNumber(i-1) << endl;
        
        cout << "Push F to continue!\n";
        cin >> bottom;
        return 0;
    }
    
    
}

