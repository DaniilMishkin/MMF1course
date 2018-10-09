//
//  main.cpp
//  10.10.18
//
//  Created by Даниил Мишкин on 04/10/2018.
//  Copyright © 2018 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double progression(int n) {
    float sum=0;
    for (int i=1; i<n+1; i++) {
        sum=(1./i)+sum;
    }
    return sum;
}

int ndegree (int n) {
    if (n==0) {
        return 1;
    } else {
        return ndegree(n-1)*2;
    }
}

double progression2 (int n){
    double sum=2;
    for (int i=2; i<n+1 ; i++) {
       sum=sum*(1+(1./pow(i,2)));
    }
    return sum;
}

double progression3 (int n){
    double sum=0.5;
    for (int i=2; i<n+1; i++) {
        sum=sum+(1./i*(i+1));
    }
    return sum;
}

double fifthdegree (int n) {
    double sum=1;
    for (int i=2; i<n+1; i++) {
        sum=sum+(1./pow(i,5));
    }
    return sum;
}

double progressiondegree(int n){
    double sum=0;
    for (int i=1; i<n+1; i++) {
        sum=sum+(1./(pow(2*i+1,2)));
    }
    return sum;
}

double progressiondegree2(int n){
    double sum=0;
    for (int i=1; i<n+1; i++) {
        double one=pow(-1,i);
        sum=sum+(one/(2*i+1));
    }
    return sum;
}

int factorial(int n){
    if (n==0){
        return 1;
    } else {
        return factorial(n-1)*n;
    }
}

double case8(int n){
    double sum=0;
    for (int i=1; i<n+1; i++) {
        sum=sum+(factorial(i)/progression(i));
    }
    return sum;
}

double sqrroot(int n){
    double sum=sqrt(2);
    for (int i=2; i<n+1; i++) {
        sum=sqrt(sum+sqrt(2));
    }
    return sum;
}

double case10progression(int n) {
    double sum=0;
    for (int i=1; i<n+1; i++) {
        sum=sum+sin(1);
    }
    return sum;
}

double  case10(int n){
    double sum=0;
    for (int i=1; i<n+1; i++) {
    sum=sum+(1./case10progression(i));
    }
    return sum;
}
// Main function


int main() {
    cout << "Press:\n"<< "1 to count the first task\n" << "2 to count the second task\n" << "3 to count third task\n" << "4 to count the fourth task\n" << "5 to count the fifth task\n" << "6 to count the sixth task\n" << "7 to count the seventh task\n" << "8 to count the eighth\n" << "9 to count the ninth task\n" << "0 to count the tenth task\n";
    
    int i;
    
    cin >> i;
    
    switch (i) {
        case 1:
            int number;
            char bottom;
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << progression(number) << "\nPress F to continue with task 1 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 2:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << ndegree(number) << "\nPress F to continue with task 2 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 3:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << progression2(number) << "\nPress F to continue with task 3 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 4:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << progression3(number) << "\nPress F to continue with task 4 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 5:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << fifthdegree(number) << "\nPress F to continue with task 5 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 6:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << progressiondegree(number) << "\nPress F to continue with task 6 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 7:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << progressiondegree2(number) << "\nPress F to continue with task 7 or any other to exit\n"
                ;cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 8:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << case8(number) << "\nPress F to continue with task 8 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
            
        case 9:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << sqrroot(number) << "\nPress F to continue with task 9 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f');
            
            break;
            
        case 0:
            do {
                cout << "enter your number: ";
                cin >> number;
                cout << case10(number) << "\nPress F to continue with task 10 or any other to exit\n";
                cin >> bottom;
            } while (bottom == 'f' || bottom == 'F');
            cout << "You exited!";
            
            break;
    }
 
    return 0;
    
}
