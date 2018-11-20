//
//  Library.cpp
//  7.11.18
//
//  Created by Даниил Мишкин on 04/11/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "math.h"

long long GetBinNumber (int number) {
    int i = 1;
    long long binNumber = 0;
    while (number != 0 ) {
        binNumber = binNumber + ((number % 2) * pow(10,i));
        number = number / 2;
        i++;
    }
    return binNumber  / 10;
}


void  GetAmountOfDigits (long long number, int &sumOfZeroes, int &sumOfOnes) {
    
    sumOfZeroes = 0;
    sumOfOnes = 0;
    while (number != 0) {
        if (number % 10 == 1) {
            sumOfOnes++;
        } else {
            sumOfZeroes++;
        }
        number /= 10;
    }
}

int GetSumOfSymbols (int number, char symbol){
    int sumSymbol = 0;
    while (number != 0) {
        
        if (number % 16 > 9) {
            switch (number % 16) {
                case 10:
                    if (symbol == 'a' || symbol == 'A') {
                        sumSymbol++;
                    }
                    break;
                    
                case 11:
                    if (symbol == 'b' || symbol == 'B') {
                        sumSymbol++;
                    }
                    break;
                    
                case 12:
                    if (symbol == 'c' || symbol == 'C') {
                        sumSymbol++;
                    }
                    break;
                    
                case 13:
                    if (symbol == 'd' || symbol == 'D') {
                        sumSymbol++;
                    }
                    break;
                    
                case 14:
                    if (symbol == 'e' || symbol == 'E') {
                        sumSymbol++;
                    }
                    break;
                    
                case 15:
                    if (symbol == 'f' || symbol == 'F') {
                        sumSymbol++;
                    }
                    break;
                    ;
            }
        } else {
            if (symbol == (number % 16)) {
                sumSymbol++;
            };
        }
        number/=16;
    }
   
    return sumSymbol;
    
}

