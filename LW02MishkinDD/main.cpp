//
//  main.cpp
//  LW02MishkinDD
//
//  Created by Даниил Мишкин on 17/03/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include "Matrix.h"
#include "cmath"

using namespace MatrixLibrary;
using namespace std;


int main() {
    int matrixSize = inputSize();
    int accuracy = inputAccuracy();
    
    double** firstMatrix = allocateMemoryDouble(matrixSize, matrixSize);
    double** secondMatrix = allocateMemoryDouble(matrixSize, matrixSize);
    
    
    cout << endl << "Matrix without Taylor series: \n";
    fillMatrix(firstMatrix, matrixSize, matrixSize, formula);
    displayMatrix(firstMatrix, matrixSize, matrixSize);
    
    cout << endl << "Matrix with Taylor series: \n";
    fillMatrix(firstMatrix, matrixSize, matrixSize, accuracy, formulaTeylor);
    displayMatrix(firstMatrix, matrixSize, matrixSize);
    
    cout << endl << "Max difference of matrix: " << maxMatrixDifference(firstMatrix, secondMatrix, matrixSize, matrixSize) << endl;
    
    
    return 0;
}
