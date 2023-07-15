//
//  numc.hpp
//  neuralnet
//
//  Created by Prajwal Neupane on 7/14/23.
//

#ifndef numc_h
#define numc_h

#include <stdio.h>

namespace numc {

// creates a 2D array aka matrix
int** initMatrix(int m, int n){
    int** arr = new int*[m];
    
    for(int i = 0; i < m; ++i){
        arr[i] = new int[n];
    }
    return arr;
}

void displayMatrix(int** arr, int rows, int columns){
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            std:: cout << "  " << arr[i][j] << " ";
        }
        std:: cout<< std:: endl;
    }
    std:: cout << std:: endl;
}

void deallocateMatrix(int** arr, int rows){
    for (int i = 0; i < rows; ++i){
        delete[] arr[i];
    }
    
    delete[] arr;
}

int** transpose(int** arr, int rows, int columns){
    int** transposedMatrix = initMatrix(columns, rows);
    
    for (int i = 0; i < columns; ++i){
        for (int j = 0; j < rows; ++j){
            transposedMatrix[i][j] = arr[j][i];
        }
        
    }
    
    return transposedMatrix;
}

}

#endif /* numc_hpp */
