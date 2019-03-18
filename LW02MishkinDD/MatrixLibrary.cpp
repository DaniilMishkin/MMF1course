//
//  MatrixLibrary.cpp
//  LW02MishkinDD
//
//  Created by Даниил Мишкин on 17/03/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include "Matrix.h"
#include "cmath"

using namespace std;

int MatrixLibrary::inputSize() {
    int matrixSize;
    
    cout << "Enter size of your square matrix (N*N): ";
    cin >> matrixSize;
    
    return matrixSize;
}


int MatrixLibrary::inputAccuracy() {
    int accuracy;
    
    cout << "Enter accurance (numbers after comma): ";
    cin >> accuracy;
    
    return accuracy;
}


double** MatrixLibrary::allocateMemoryDouble(int rows, int colums) {
    double** matrix = new double*[rows];
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[colums];
    }
    
    return matrix;
}

void MatrixLibrary::fillMatrix(double** matrix, int rows, int colums, value formula) {
    for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < colums; j++) {
            matrix[i][j] = formula(i, j);
        }
    }
}

void MatrixLibrary::fillMatrix(double** matrix, int rows, int colums, int accuracy, exactValue formula) {
    for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < colums; j++) {
            matrix[i][j] = formula(i, j, accuracy);
        }
    }
}

void MatrixLibrary::displayMatrix(double** matrix, int rows, int colums) {
    for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < colums; j++) {
            cout << " " << matrix[i][j];
        }
        
        cout << endl;
    }
}

double MatrixLibrary::taylorSin(double number, int accuracy) {
    const double PI = 3.14159265358979323846;
    number = fmod(number, PI * 2);
    double sin = 0, term = number;
    int i = 1;
    
    while (abs(term) > pow(0.1, accuracy)) {
        sin += term;
        term *= -1.0*(number * number) / (2 * i) / (2 * i + 1);
        i++;
    }
    return sin;
}

double MatrixLibrary::taylorCos(double number, int accuracy) {
    
    const double PI = 3.14159265358979323846;
    number = fmod(number, PI * 2);
    double cos = 0, term = 1;
    int i = 1;
    
    while (abs(term) > pow(0.1, accuracy))
    {
        cos += term;
        term *= -1.0*(number * number) / (2 * i) / (2 * i - 1);
        i++;
    }
    
    return cos;
}


double MatrixLibrary::maxMatrixDifference(double** firstMatrix, double** secondMatrix, int rows, int colums) {
    double maxDifference = 0;
    double currentDifference = 0;
    
    for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < colums; j++) {
            
            currentDifference = fabs(secondMatrix[i][j] - firstMatrix[i][j]);
            
            if (currentDifference > maxDifference) {
                maxDifference = currentDifference;
            }
        }
    }
    
    return maxDifference;
}


double MatrixLibrary::formula(int i, int j) {
    if (i == 2 * j) {
        return (pow(M_E, sin(i + j)) + cos(pow(i + j, 2))) / sin(pow(i + 1, 2));
    } else {
        return (double) i;
    }
}


double MatrixLibrary::formulaTeylor(int i, int j, int accuracy) {
    if (i == 2 * j) {
        return (pow(M_E, taylorSin(i + j, accuracy)) + taylorCos(pow(i + j, 2), accuracy)) / taylorSin(pow(i + 1, 2), accuracy);
    } else {
        return (double)i;
    }
}
