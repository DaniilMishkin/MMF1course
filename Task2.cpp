//
//  Task2.cpp
//  ControlWork19.12.18
//
//  Created by Даниил Мишкин on 19/12/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#include <iostream>

using namespace std;

void encoding(char[], int[], char[]);
void decoding(int[], char[], char[]);
void codingTests();
bool equals(char[], char[]);
int getLength(char *);

int main()
{
    codingTests();
    
    return 0;
}

int getLength(char * string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void encoding(char source[], int encoding[], char rule[]) {
    for (int i = 0; i < getLength(source); i++) {
        for (int j = 0; j < getLength(rule) ; j++) {
            if (source[i] == rule[j]) {
                encoding[i] = j + 1;
                break;
            }
        }
    }
}

void decoding(int source[], char decoding[], char rule[]){
    int i = 0, length = 0;
    while (source[i]) {
        length++;
        i++;
    }
    
    for (i = 0; i < length; i++) {
            decoding[i] = rule[source[i] - 1];
        }
    decoding[length] = '\0';
}

bool equals(char lhs[], char rhs[]){
    if (getLength(lhs) != getLength(rhs)) {
        return false;
    }
    
    for (int i = 0; i < getLength(lhs); i++){
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

void codingTests(){
    const int length = 30;
    
    char source[length] = "i think my c++ code works!!!!";
    
    int numbers[length - 1] = { 0 };
    
    char rule[30] = "zyxwvutsrqponmlkjihgfedcba!+ ";
    
    encoding(source, numbers, rule);
    
    char expected[length];
    
    decoding(numbers, expected, rule);
    
    cout << equals(source, expected) << endl;
}





