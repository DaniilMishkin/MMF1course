//
//  StringLibrary.h
//  HWLibraries
//
//  Created by Даниил Мишкин on 17/12/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#ifndef StringLibrary_h
#define StringLibrary_h

#include <iostream>

const int M = 256;

using namespace std;

void displayArray(char*);

void displayMatrix(char a[][M], int n, int m);

bool isLetter(char);

int getLength(char*);

void arrayOfWords(char*, char[M][M]);

int substringPosition(char*, char*, int);

void stringReplacement(char*, char*, char*, char*);

void stringErase(char*, char*);


void displayMatrix(char a[][M], int n, int m)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j];
        }
        
        cout << endl;
    }
}

bool isLetter(char symbol){
    if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
        return true;
    }
    return false;
}

int getLength(char* source){
    int length = 0;
    while (source[length]){
        length++;
    }
    return length;
}

void arrayOfWords(char* string, char newString[M][M])
{
    
    int nextLetter = 0, nextWord = 0, i = 0;
    while (string[i] != '\0'){
        if (isLetter(string[i])){
            newString[nextLetter][nextWord] = string[i];
            nextLetter++;
        }
        else{
            if (isLetter(string[i + 1]))
            {
                nextWord++;
                nextLetter = 0;
            }
        }
        i++;
    }
    
}

int substringPosition(char* string, char* substring, int start){
    int n = getLength(string),
    m = getLength(substring);
    if (m > n){
        return -1;
    }
    int count = 0, index = -1;
    for (int i = start; i < n; i++){
        for (int j = 0; j < m; j++){
            if (substring[j] == string[i + count]){
                index = i;
                count++;
                if (j == m - 1){
                    return index;
                }
                else{
                    continue;
                }
            }
            else{
                index = -1;
                count = 0;
                break;
            }
        }
    }
    return index;
}

void stringReplacement(char* string, char* toBeReplaced, char* replace, char* newString){
    
    int newLength = getLength(replace), oldLength = getLength(toBeReplaced), sLength = getLength(string), start = 0, oldStart = 0, count = 0, difference = newLength - oldLength;
    int index = substringPosition(string, toBeReplaced, start);
    for (int i = 0; i < index; i++){
        newString[i] = string[i];
    }
    while (index != -1){
        for (int j = index + count*(difference) , i = 0; j < index + newLength + count*(difference); j++, i++){
            newString[j] = replace[i];
        }
        start = index + newLength;
        int newIndex = substringPosition(string, toBeReplaced, start);
        while (newIndex != -1){
            for (int i = index + newLength + count * (difference), j = index + oldLength; j < newIndex; i++, j++){
                newString[i] = string[j];
            }
            break;
        }
        while (newIndex == -1){
            for (int i = index + newLength +count*(difference) , j = index + oldLength; j < sLength; i++, j++){
                newString[i] = string[j];
            }
            break;
        }
        
        index = substringPosition(string, toBeReplaced, start);
        count++;
    }
}

void stringErase(char* string, char* erase){
    int sLength = getLength(string), eraseLength = getLength(erase);
    int index = substringPosition(string, erase, 0);
    while (index != -1)
    {
        for (int i = index, j = index + eraseLength; i < sLength; i++, j++)
        {
            string[i] = string[j];
        }
        index = substringPosition(string, erase, 0);
    }
}

void displayArray(char* string){
    for (int i = 0; i < getLength(string); i++)
    {
        cout << "string[" << i + 1 << "] = " << string[i] << endl;
    }
}

#endif /* StringLibrary_h */
