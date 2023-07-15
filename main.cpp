//
//  main.cpp
//  neuralnet
//
//  Created by Prajwal Neupane on 7/14/23.
//

#include <iostream>
#include "numc.h"
using namespace numc;


// func -> get_labels -> input (data point) -> output (array of corresponding labels: Y)


// func -> data_preprocessor -> input (image filename) -> output (array of image pixel values: X)
int** data_preprocessor(int rows/* pass filename with image, use random numbers for now */){
    int row = rows;
    int cols = 2;
    int** data = initMatrix(row, cols);
    

    for (int i = 0; i < rows; ++i){
        data[i][0] = i;
        data[i][1] = 2*i + 5;
    }
    
    return data;
}

// func -> train_test_split -> input (X : data_preprocessor) -> output (array of 4 arrays: train_set_x, train_set_y, test_set_x, test_set_y)

int** train_test_split(int** arr, float split_ratio, int rows, int cols){
    int train_index = static_cast<int>(split_ratio * rows);
    int test_size = rows - train_index;
    
    int** train_x = initMatrix(train_index, cols-1);
    int** train_y = initMatrix(train_index, 1);
    
    int** test_x = initMatrix(test_size, cols-1);
    int** test_y = initMatrix(test_size, 1);
    
    int** return_results = initMatrix(1, 5);
    
    
    // split
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            if (i < train_index && j < cols){
                train_x[i][j] = arr[i][j];
            }else if (j == cols){
                train_y[j][i] = arr[j][i];
            }
            
            if (i > train_index && j < cols){
                test_x[i][j] = arr[i][j];
            }else if (j == cols){
                test_y[i][j] = arr[i][j];
            }

        }
    }
    
    return_results[0][0] = **train_x;
    return_results[0][1] = **train_y;
    return_results[0][2] = **test_x;
    return_results[0][3] = **test_y;
    return_results[0][4] = train_index;
    
    return return_results;
}


int main() {
    
    int data_n = 50;
    
    int** data = data_preprocessor(data_n);
    
    displayMatrix(data, data_n, 2);
    
    int** split_matricies = train_test_split(data, 0.8, data_n, 2);
    
    int train_size = split_matricies[0][4];
    int test_size = data_n - train_size;
    
    int** train_x = reinterpret_cast<int**>(split_matricies[0][0]);
    int** train_y = reinterpret_cast<int**>(split_matricies[0][1]);
    int** test_x = reinterpret_cast<int**>(split_matricies[0][2]);
    int** test_y = reinterpret_cast<int**>(split_matricies[0][3]);

    
    
    std::cout << "train_x: " << std::endl;
    displayMatrix(train_x, train_size, 1);
    
    std::cout << "train_y: " << std::endl;
    displayMatrix(train_y, train_size, 1);
    
    std::cout << "test_x: " << std::endl;
    displayMatrix(test_x, test_size, 1);
    
    std::cout << "test_y: " << std::endl;
    displayMatrix(test_y, test_size, 1);
    return 0;
}
