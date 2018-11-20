//
//  main.cpp
//  7.11.18
//
//  Created by Даниил Мишкин on 04/11/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include "Library.h"

using namespace std;

long long GetBinNumber (int number);
void  GetAmountOfDigits (long long number, int &sumOfZeroesp, int &sumOfOnesp);
int GetSumOfSymbols (int number, char symbol);

int main () {
    char buttom = 'f';
    while (buttom == 'f' || buttom == 'F') {
        cout << "Enter your numbers in the array: ";
    
        int number[2];
    
        for (int i=0; i<2; i++){
            cin >> number[i];
        }
    
    
        int sumOfZeroes, sumOfOnes;
        for (int i=0; i<2; i++) {
            GetAmountOfDigits(GetBinNumber(number[i]), sumOfZeroes, sumOfOnes);
        
            cout << "Bin code of " << number[i] << " is " << GetBinNumber(number[i]) << endl << "Amount of '1' is " << sumOfOnes <<  " and of '0' is " << sumOfZeroes << endl;
        }
    
        cout << "Enter number: \n";
        int numeral;
        cin >> numeral;

        cout << "Enter symbol: \n";
        char symbol;
        cin >> symbol;

        cout << "Amount of '" << symbol << "' is " << GetSumOfSymbols(numeral, symbol)<< endl;
    
        cout << "Push F to continue!\n";
        cin >> buttom;
        
    }
    return 0;
}


