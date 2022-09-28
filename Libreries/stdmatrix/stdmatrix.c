//
// Created by Gabriele Scannagatti on 27/09/22.
//
#include<stdio.h>
#include<stdlib.h>
#include "stdmatrix.h"

int allocMatrix_s(int row, int col, int** out_matrix) {
    out_matrix = (int**)malloc(row*sizeof (int*));

    if(m==NULL)
        return MATRIX_ALLOCATION_ERROR;

    int index;
    int alloc_error = 0;

    for(index = 0; index<row; index++) {
        out_matrix[index] = (int*) malloc(col*sizeof (int));
        if(out_matrix[index] == NULL){
            alloc_error = 1;
            break;
        }
    }

    // If Something goes wrong allocated memory will be cleaned
    if(alloc_error) {
        for(int i=0; i<index; i++)
            free(out_matrix[i]);
        free(out_matrix);
        out_matrix = NULL;
        return MATRIX_ALLOCATION_ERROR;
    }
    return ERROR_SUCCESS;
}

int** allocMatrix(int row, int col) {
    int** m = (int**) malloc(row*sizeof (int*));
    for(int i=0; i<row; i++)
        m[i] = (int*)malloc(col*sizeof(int));
    return m;
}

void readMatrix(int** matrix, int row, int col) {
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            scanf("%d", &matrix[i][j]);
}

int** addMatrix(int** a, int** b, int row, int col){
    int** m = NULL;
    if(allocMatrix_s(row, col, m) != ERROR_SUCCESS)
        return m;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            m[i][j] = a[i][j] + b[i][j];

    return m;
}

int addMatrix_s(int** a, int** b, int row_a, int col_a, int row_b, int col_b, int** out_matrix){
    if(row_a != row_b || col_a != col_b)
        return INCOMPATIBLE_MATRICES_ERROR;

    for(int i=0; i<row_a; i++)
        for(int j=0; j<col_a; j++)
            out_matrix[i][j] = a[i][j] + b[i][j];
    return ERROR_SUCCESS;
}