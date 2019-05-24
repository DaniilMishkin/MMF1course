//
//  main.cpp
//  ClassWork
//
//  Created by Даниил Мишкин on 22/05/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#include <fstream>
#include <iostream>
#include "Student.h"

using namespace std;

Student* readFromFile(char* fileName);

void DisplayFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);

void intoBinary(char* binaryFile, Student* students);

int main() {
    
    char* textFile = "task.txt";
    char* binaryFile ="task.bin";
   
    Student* student;
    
    student = readFromFile(textFile);
    
    intoBinary(binaryFile, student);
    
    DisplayFile(binaryFile);
}



void DisplayFile(char* fileName)
{
    ifstream streamIn(fileName, ios::binary);
    if (!streamIn.is_open())
    {
        cout << "Can't open file to read!";
        SystemFun();
        return;
    }
    int bufSize = sizeof(Student);
    Student* man = new Student;
    while (streamIn.read((char*)man, bufSize))
    {
        man->DisplayStudent();
    }
    streamIn.close();
}

void SystemFun()
{
    cout << endl;
    system("pause");
    system("cls");
}

void InitNameFile(char* fileName)
{
    cout << "Enter the name of file: " << endl;
    cin.ignore();
    cin.getline(fileName, 256, '\n');
    system("cls");
}

Student* readFromFile(char* fileName) {
    
    ifstream streamIn;
    streamIn.open(fileName);
    
    if (!streamIn.is_open()) {
        
        cout << "Cannot open file to read!" << endl;
        system("pause");
        exit(1);
    }
    
    char Name[10];
    char Surname[10];
    char Faculty[10];
    int Marks[M];
    
    streamIn >> Name;
    streamIn >> Surname;
    streamIn >> Faculty;
    
    for (int j = 0; j < M; j++) {
    
        streamIn >> Marks[j];
    }
    
    Student* student;
    
    student->SetStudent(Name, Surname, Faculty, Marks);
    
    return student;
}

void intoBinary(char* binaryFile, Student* student) {
    
    ofstream streamOut;
    streamOut.open(binaryFile, ios::binary);
    
    if (!streamOut.is_open()) {
        
        cout << " \n Can't open file to write! ";
        SystemFun();
        return;
    }
    
    int Size = sizeof(Student);
    
    streamOut.write((char*)&student, Size);
    
    streamOut.close();
}
