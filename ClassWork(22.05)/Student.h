//
//  Header.h
//  ClassWork
//
//  Created by Даниил Мишкин on 22/05/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#ifndef student_h
#define student_h

const int N = 50;
const int M = 4;

class Student
{
public:
    Student(){}
    Student(char*, char*, char*, int*);
    ~Student(){}
    void SetFirstName(char*);
    void SetLastName(char*);
    void Setfaculty(char*);
    void SetMarks(int*);
    void SetStudent(char*, char*, char*, int*);
    double GetMiddleMark();
    char* GetFirstName();
    char* GetLastName();
    char* Getfaculty();
    void EnterStudent();
    void DisplayStudent();
private:
    char firstName[N]{}, lastName[N]{}, faculty[N]{};
    int marks[M]{};
    double middleMark{};
    void SetMiddleMark();
};

#endif
