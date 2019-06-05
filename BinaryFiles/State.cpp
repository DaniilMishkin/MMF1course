//
//  Cars.cpp
//  BinaryFiles
//
//  Created by Даниил Мишкин on 04/06/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include <string>
#include "State.h"

using namespace std;

State::State(char* name, char* capital, char* language, int population, int territory, char* money, char* politicalSystem, char* president) {
    
    this->SetState(name, capital, language, population, territory, money, politicalSystem, president);
}

void State::SetState(char* name, char* capital, char* language, int population, int territory, char* money, char* politicalSystem, char* president)
{
    this->SetName(name);
    this->SetCapital(capital);
    this->SetLanguage(language);
    this->SetPopulation(population);
    this->SetTerritory(territory);
    this->SetMoney(money);
    this->SetPoliticalSystem(politicalSystem);
    this->SetPresident(president);
}

void State::SetName(char* name) {
    
    strcpy(this->name, name);
}

void State::SetCapital(char* capital) {
    
    strcpy(this->capital, capital);
}

void State::SetLanguage(char* language) {
    
    strcpy(this->language, language);
}

void State::SetPopulation(int population) {
    
    if (population <= 0) {
        
        throw invalid_argument("Please enter valid number!");
    }
    
    this->population = population;
}

void State::SetTerritory(int territory) {
    
    if (territory <= 0) {
        
        throw invalid_argument("Please enter valid number!");
    }
    
    this->territory = territory;
}

void State::SetMoney(char* money) {
    
    strcpy(this->money, money);
}

void State::SetPoliticalSystem(char* politicalSystem) {
    
    strcpy(this->politicalSystem, politicalSystem);
}

void State::SetPresident(char* president) {
   
    strcpy(this->president, president);
}



char* State::GetName() {
    
    return this->name;
}

char* State::GetCapital() {
    
    return this->capital;
}

char* State::GetLanguage() {
    
    return this->language;
}

int State::GetPopulation() {
    
    return this->population;
}

int State::GetTerritory() {
    
    return this->territory;
}

char* State::GetMoney() {
    
    return this->money;
}

char* State::GetPoliticalSystem() {
    
    return this->politicalSystem;
}

char* State::GetPresident() {
    
    return this->president;
}

void State::DisplayState() {
    
    cout << "Name of state: " << this->name << endl;
    cout << "Capital: " << this->capital << endl;
    cout << "State language: " << this->language << endl;
    cout << "Population: " << this->population << endl;
    cout << "State territor: " << this->territory << endl;
    cout << "Money: " << this->money << endl;
    cout << "Political system: " << this->politicalSystem << endl;
    cout << "Head of state: " << this->president << endl;
}

    void State::EnterState() {
    
    const int N = 256;
    
    char name[N] = "", capital[N] = "", language[N] = "", money[N] = "", politicalSystem[N] = "", president[N] = "";
    
    cout << "Enter a state name: ";
    cin.ignore();
    cin.getline(name, N, '\n');
    cout << "Enter the capital of the state: ";
    cin.getline(language, N, '\n');
    cout << "Enter the currency unit: ";
    cin.getline(money, N, '\n');
    cout << "Enter the politycal system: ";
    cin.getline(politicalSystem, N, '\n');
    cout << "Enter the head of the state: ";
    cin.getline(president, N, '\n');
    
    int population, territory;
    cout << "Enter the number of people: ";
    cin >> population;
    cout << "\n";
    
    cout << "Enter the area of the state: ";
    cin >> territory;
    cout << "\n";
    
    
    this->SetState(name , capital, language, population, territory, money, politicalSystem, president);
}

