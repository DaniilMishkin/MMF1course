//
//  main.cpp
//  BinaryFiles
//
//  Created by Даниил Мишкин on 04/06/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//


#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include "State.h"

using namespace std;

int max(int, int);
void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();
int SortingMenu();

int main()
{
    char fileName[N] = "/Users/daniilmiskin/Desktop/xcode/BinaryFiles/BinaryFiles/State.bin";
    enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
    while (true)
    {
        int key = Menu();
        if (key == Exit)
            return 0;
        system("cls");
        switch (key)
        {
            case Init:
                InitNameFile(fileName);
                SystemFun();
                break;
            case Create:
                InitFile(fileName);
                SystemFun();
                break;
            case Display:
                DisplayFile(fileName);
                SystemFun();
                break;
            case Add:
                AddToEndFile(fileName);
                SystemFun();
                break;
            case Change:
                ChangeFile(fileName);
                SystemFun();
                break;
            case Remove:
                RemoveFromFile(fileName);
                SystemFun();
                break;
            case Sort:
                SortingFile(fileName);
                SystemFun();
                break;
            default:
                cout << "\nIncorrect input! Try again!";
                SystemFun();
        }
    }
}

void InitFile(char* fileName)
{
    ofstream streamOut;
    streamOut.open(fileName, ios::binary);
    if (!streamOut.is_open())
    {
        cout << "\nCan't open file to write!";
        SystemFun();
        return;
    }
    int bufSize = sizeof(State);
    State state;
    char ok = 'y';
    while (ok == 'y')
    {
        state.EnterState();
        streamOut.write((char*)&state, bufSize);
        cout << " If you want to continue, press 'y' :";
        cin >> ok;
    }
    streamOut.close();
}

void AddToEndFile(char* fileName)
{
    ofstream streamOut(fileName, ios::app | ios::binary);
    if (!streamOut.is_open())
    {
        cout << "Can't open file to write!";
        SystemFun();
        return;
    }
    int bufSize = sizeof(State);
    State state;
    char Ok = 'y';
    while (Ok == 'y')
    {
        state.EnterState();
        streamOut.write((char*)&state, bufSize);
        cout << " If you want to continue, press 'y' : ";
        cin >> Ok;
    }
    streamOut.close();
}

void ChangeFile(char* fileName)
{
    fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
    if (!streamInOut)
    {
        cout << "Can't open file to read and write!";
        SystemFun();
        return;
    }
    int bufSize = sizeof(State);
    State state;
    long position;
    InitNumber(position);
    streamInOut.seekp((position - 1) * bufSize, ios::beg);
    state.EnterState();
    streamInOut.write((char*)&state, bufSize);
    streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
    fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
    if (!streamInOut.is_open())
    {
        cout << "Can't open file to read and write!";
        SystemFun();
        return;
    }
    streamInOut.seekp(0, ios::end);
    long n = streamInOut.tellp();
    int bufSize = sizeof(State);
    State state;
    long Position;
    InitNumber(Position);
    streamInOut.seekp(Position * bufSize, ios::beg);
    while (streamInOut.read((char*)&state, bufSize))
    {
        streamInOut.seekp(-2 * bufSize, ios::cur);
        streamInOut.write((char*)&state, bufSize);
        streamInOut.seekp(bufSize, ios::cur);
    }
    streamInOut.close();
//    int diskriptorFile = _open(fileName, 2);
//    _chsize(diskriptorFile, n - bufSize);
//    _close(diskriptorFile);
}

void SortingFile(char* fileName)
{
    bool flag = true;
    while (flag)
    {
        fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
        if (!streamInOut.is_open())
        {
            cout << "Can't open file to read and write!";
            SystemFun();
            return;
        }
        flag = false;
        State stateOne, stateTwo;
        int bufSize = sizeof(State);
        streamInOut.read((char*)&stateOne, bufSize);
        enum { Name = 1, Capital, Language, Population, Territory, Money, PoliticalSystem, President, Exit };
        int key = SortingMenu();
        if (key == Exit)
        {
            return;
        }
        system("cls");
        switch (key)
        {
            case Name:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    int length = max(strlen(stateTwo.GetName()), strlen(stateOne.GetName()));
                    for (int i = 0; i < length; i++)
                    {
                        if (stateTwo.GetName()[i] < stateOne.GetName()[i])
                        {
                            streamInOut.seekp(-2 * bufSize, ios::cur);
                            streamInOut.write((char*)&stateTwo, bufSize);
                            streamInOut.write((char*)&stateOne, bufSize);
                            flag = true;
                            break;
                        }
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            case Capital:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    int length = max(strlen(stateTwo.GetCapital()), strlen(stateOne.GetCapital()));
                    for (int i = 0; i < length; i++)
                    {
                        if (stateTwo.GetCapital()[i] < stateOne.GetCapital()[i])
                        {
                            streamInOut.seekp(-2 * bufSize, ios::cur);
                            streamInOut.write((char*)&stateTwo, bufSize);
                            streamInOut.write((char*)&stateOne, bufSize);
                            flag = true;
                            break;
                        }
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            case Language:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    int length = max(strlen(stateTwo.GetLanguage()), strlen(stateOne.GetLanguage()));
                    for (int i = 0; i < length; i++)
                    {
                        if (stateTwo.GetLanguage()[i] < stateOne.GetLanguage()[i])
                        {
                            streamInOut.seekp(-2 * bufSize, ios::cur);
                            streamInOut.write((char*)&stateTwo, bufSize);
                            streamInOut.write((char*)&stateOne, bufSize);
                            flag = true;
                            break;
                        }
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            case Population:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    if (stateTwo.GetPopulation() < stateOne.GetPopulation())
                    {
                        streamInOut.seekp(-2 * bufSize, ios::cur);
                        streamInOut.write((char*)&stateTwo, bufSize);
                        streamInOut.write((char*)&stateOne, bufSize);
                        flag = true;
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            case Territory:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    if (stateTwo.GetTerritory() < stateOne.GetTerritory())
                    {
                        streamInOut.seekp(-2 * bufSize, ios::cur);
                        streamInOut.write((char*)&stateTwo, bufSize);
                        streamInOut.write((char*)&stateOne, bufSize);
                        flag = true;
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            case Money:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    int length = max(strlen(stateTwo.GetMoney()), strlen(stateOne.GetMoney()));
                    for (int i = 0; i < length; i++)
                    {
                        if (stateTwo.GetMoney()[i] < stateOne.GetMoney()[i])
                        {
                            streamInOut.seekp(-2 * bufSize, ios::cur);
                            streamInOut.write((char*)&stateTwo, bufSize);
                            streamInOut.write((char*)&stateOne, bufSize);
                            flag = true;
                            break;
                        }
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            case PoliticalSystem:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    int length = max(strlen(stateTwo.GetPoliticalSystem()), strlen(stateOne.GetPoliticalSystem()));
                    for (int i = 0; i < length; i++)
                    {
                        if (stateTwo.GetPoliticalSystem()[i] < stateOne.GetPoliticalSystem()[i])
                        {
                            streamInOut.seekp(-2 * bufSize, ios::cur);
                            streamInOut.write((char*)&stateTwo, bufSize);
                            streamInOut.write((char*)&stateOne, bufSize);
                            flag = true;
                            break;
                        }
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            case President:
                while (streamInOut.read((char*)&stateTwo, bufSize))
                {
                    int length = max(strlen(stateTwo.GetPresident()), strlen(stateOne.GetPresident()));
                    for (int i = 0; i < length; i++)
                    {
                        if (stateTwo.GetPresident()[i] < stateOne.GetPresident()[i])
                        {
                            streamInOut.seekp(-2 * bufSize, ios::cur);
                            streamInOut.write((char*)&stateTwo, bufSize);
                            streamInOut.write((char*)&stateOne, bufSize);
                            flag = true;
                            break;
                        }
                    }
                    streamInOut.seekp(-bufSize, ios::cur);
                    streamInOut.read((char*)&stateOne, bufSize);
                }
                break;
                
            default:
                cout << "\nIncorrect input! Try again!";
                SystemFun();
        }
        streamInOut.close();
    }
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
    int bufSize = sizeof(State);
    State* state = new State;
    while (streamIn.read((char*)state, bufSize))
    {
        state->DisplayState();
    }
    streamIn.close();
}

void InitNumber(long& n)
{
    cout << "Enter the number of record:" << endl;
    cin >> n;
    system("cls");
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

int Menu()
{
    int k;
    cout << "\n Enter the number - the mode of operations with the file:"
    "\n 1 - INITIALIZE THE NAME OF THE FILE"
    "\n 2 - INITIALIZE FILE WITH ELEMENTS"
    "\n 3 - VIEW THE CONTENT OF THE FILE"
    "\n 4 - ADD AN ELEMENT TO THE FILE"
    "\n 5 - CHANGE AN ELEMENT IN THE FILE"
    "\n 6 - REMOVE AN ELEMENT IN THE FILE"
    "\n 7 - SORT AN ELEMENT IN THE FILE"
    "\n 8 - EXIT\n";
    cin >> k;
    return k;
}

int SortingMenu()
{
    int k;
    cout << "\n Enter the number of the characteristic:"
    "\n 1 - STATE"
    "\n 2 - CAPITAL"
    "\n 3 - STATE LANGUAGE"
    "\n 4 - POPULATION"
    "\n 5 - TERRITORY"
    "\n 6 - MONEY"
    "\n 7 - POLITICAL SYSTEM"
    "\n 8 - HEAD OF STATE"
    "\n 9 - EXIT\n";
    cin >> k;
    return k;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
