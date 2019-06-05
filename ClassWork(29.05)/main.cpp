//
//  main.cpp
//  ClassWork(29.05)
//
//  Created by Даниил Мишкин on 29/05/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//


#include <fstream>
#include <iostream>


const int N = 5;
const int K = 10;
const int L = 7;


using namespace std;


void DisplayFile(char* , int);
void DisplayMatrix(int* , int);
void SystemFun();
void InitNameFile(char*);

void intoBinary(char* binaryFile, int);
void addToFile(char*); 
int**  unitMatrix(int);


int main() {
    
    char* inputFile1 = "‎⁨/Users/daniilmiskin/Desktop/xcode/ClassWork(29.05)/ClassWork(29.05)/input.txt";
    char* inputFile2 = "‎⁨/Users/daniilmiskin/Desktop/xcode/ClassWork(29.05)/ClassWork(29.05)/input.txt";
    char* binaryFile ="/Users/daniilmiskin/Desktop/xcode/ClassWork(29.05)/ClassWork(29.05)/output.txt";
    
    addToFile(inputFile2);
    DisplayFile(inputFile1, N);
    DisplayFile(inputFile2, N);
}


void DisplayMatrix(int* pointer, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout.width(4);
            cout << pointer[i * N + j];
        }
        cout << endl;
    }
}


void DisplayFile(char* fileName, int size)
{
    ifstream streamIn(fileName, ios::in | ios::binary);
    if (!streamIn.is_open())
    {
        cout << "Can't open file to read.";
        exit(1);
    }
    int bufSize = sizeof(int) * size * size, counter = 0;
    int* pointer = new int[size * size];
    while (streamIn.read((char*)pointer, bufSize))
    {
        cout << endl << counter + 1 << "'s  matrix " << endl;
        DisplayMatrix(pointer, size);
        counter++;
    }
    delete[] pointer;
    streamIn.close();
}


void SystemFun()
{
    cout << endl;
}


void InitNameFile(char* fileName) {
    
    cout << "Enter the name of file: " << endl;
    cin.ignore();
    cin.getline(fileName, 256, '\n');
}


int** makeUnitMatrix(int N) {
    
    int** matrix = new int*[N];
    
    for (int i = 0; i < 0; i++) {
        matrix[i] = new int[N];
        matrix[i][i] = 1;
    }
    
    return matrix;
}


void addToFile(char* nameOfFile) {
    
    ofstream streamOut;
    streamOut.open(nameOfFile, ios::binary);
    
    if (!streamOut.is_open()) {
        
        cout << " \n Can't open file to write! ";
        SystemFun();
        return;
    }
    
    int size = sizeof(makeUnitMatrix(N));
    
    for (int i = 0; i < (K - L); i++) {
    
        streamOut.write(( char* ) makeUnitMatrix(N), size);
    }
    
    streamOut.close();
}

