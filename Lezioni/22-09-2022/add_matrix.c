//
// Created by Gabriele Scannagatti on 22/09/22.
//
#include<stdio.h>
#include<stdlib.h>

void readMatrix(int row, int col, int matrix[][col]);

void addMatrix(int row, int col, int a[][col], int b[][col], int  out[][col]);

void printMatrix(int row, int col, int matrix[][col]);

int main(void){
    int r1, c1, r2, c2;
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    readMatrix(r1,c1, a);
    scanf("%d %d", &r2, &c2);
    int b[r2][c2];
    readMatrix(r2,c2, b);
    if(r1!=r2 || c1!=c2){
        printf("Le matrici non si possono sommare\n");
        exit(EXIT_FAILURE);
    }
    else{
        int res[r1][c1];
        addMatrix(r1, c1, a, b, res);
        printMatrix(r1, c1, res);
    }

    return EXIT_SUCCESS;
}

void readMatrix(int row, int col, int matrix[][col]) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
    return;
}

void printMatrix(int row, int col, int matrix[][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return;
}

void addMatrix(int row, int col, int a[][col], int b[][col], int out[][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            out[i][j] = a[i][j] + b[i][j];
    }
    return;
}
