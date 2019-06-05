//
//  State.h
//  BinaryFiles
//
//  Created by Даниил Мишкин on 04/06/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#ifndef State_h
#define State_h

const int N = 75;

class State {
    
public:
    
    State() {}
    
    State(char*, char*, char*, int, int, char*, char*, char*);
    
    ~State() {}
    
    void SetName(char*);
    void SetCapital(char*);
    void SetLanguage(char*);
    void SetPopulation(int);
    void SetTerritory(int);
    void SetMoney(char*);
    void SetPoliticalSystem(char*);
    void SetPresident(char*);
    
    void SetState(char*, char*, char*, int, int, char*, char*, char*);
    
    char* GetName();
    char* GetCapital();
    char* GetLanguage();
    int GetPopulation();
    int GetTerritory();
    char* GetMoney();
    char* GetPoliticalSystem();
    char* GetPresident();
    
    void EnterState();
    void DisplayState();
    
private:
    
    char name[N]{}, capital[N]{}, language[N]{}, money[N]{}, politicalSystem[N]{}, president[N]{};
    int population, territory;
   
};

#endif
