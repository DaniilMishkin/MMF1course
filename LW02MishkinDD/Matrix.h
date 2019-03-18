//
//  Matrix.h
//  LW02MishkinDD
//
//  Created by Даниил Мишкин on 17/03/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//


namespace MatrixLibrary {
    typedef double(*value)(int, int);
    
    typedef double(*exactValue)(int, int, int);
    
    
    int inputSize();
    
    int inputAccuracy();
    
    
    double** allocateMemoryDouble(int, int);
    
    
    void fillMatrix(double**, int, int, value);
    
    void fillMatrix(double**, int, int, int, exactValue);
    
    void displayMatrix(double**, int, int);
    
    double taylorSin(double, int);
    
    double taylorCos(double , int);
    
    double maxMatrixDifference(double**, double**, int, int);
    
    double formula(int, int);
    
    double formulaTeylor(int, int, int);
}
