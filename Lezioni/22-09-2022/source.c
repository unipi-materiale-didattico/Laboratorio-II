//
// Created by Gabriele Scannagatti on 22/09/22.
//
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    double sum = 0;
    for(int i=1; i<argc; i++){
        sum+= strtof(argv[i], NULL);
    }
    printf("%f\n", sum);
}
