//
//  main.cpp
//  LW01MishkinDD
//
//  Created by Даниил Мишкин on 28/02/2019.
//  Copyright © 2019 Даниил Мишкин. All rights reserved.
//

#include <iostream>
#include "ArrayLibrary.h"

using namespace ArrayExtension;

int main(int argc, const char * argv[]) {
    int n = 5;
    
    int* array = new int[n];
    
    array[0] = 1;
    array[1] = 2;
    array[2] = 2;
    array[3] = 4;
    array[4] = 4;
    
    displayArray(array, n);
    
    sort(makeUnique(array, n), n, 3, 2);
    
    //I NEED A LITTLE MORE TIME
    return 0;
}
