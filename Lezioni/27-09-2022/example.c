//
// Created by Gabriele Scannagatti on 27/09/22.
//

/*
 *  Funzione di lettura matrice NxM conosciuti a runtime
 *  Suppongo che siano uguali per mancanza di tempo in aula
 */

#include<stdio.h>
#include<stdlib.h>

int readInt();
int ** allocMatrix(int row, int col);
int** readMatrix(int* row, int* col);
int** sumMatrix(int** a, int** b, int row, int col);
void printMatrix(int** matrix, int row, int col);
void freeMatrix(int** m, int row);

int main(void) {
    int r1, c1, r2, c2;
    int** a = readMatrix(&r1, &c1);
    int** b = readMatrix(&r2, &c2);
    int** c = sumMatrix(a, b , r1, c2);
    printMatrix(c, r1, c1);
    freeMatrix(a, r1);
    freeMatrix(b, r2);
    freeMatrix(c, r1);
    return EXIT_SUCCESS;
}

int readInt(){
    int input;

    scanf("%d", &input);
    return input;
}

int** readMatrix(int* row, int* col) {
    int** m;
    *row=readInt();
    *col=readInt();
    m = allocMatrix(*row, *col);
    for(int i=0; i<*row; i++)
        for(j=0; j<*col; j++){
            m[i][j] = readInt();
        }
    return m;
}

int ** allocMatrix(int row, int col) {
    int ** m = (int**)malloc(row * sizeof (int*));
    if(m == NULL){
        printf("Memoria esaurita\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<row; i++){
        m[i] = (int*)malloc(col * sizeof(int));
        if(m[i] == NULL) {
            printf("Memoria esaurita\n");
            exit(EXIT_FAILURE);
        }
    }
    return m;
}

int** sumMatrix(int** a, int** b, int row, int col) {
    int** c = allocMatrix(row, col);
    for(int i =0; i<row; i++){
        for(int j=0; j<col; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int** m, int row, int col) {
    for(int i =0; i<row; i++){
        for(int j = 0; j<col; j++)
            printf("%d ", m[i][j])
        printf("\n");
    }
}

void freeMatrix(int** m, int row){
    for(int i=0; i< row; i++)
        free(m[i]);
    free(m);
    return;
}