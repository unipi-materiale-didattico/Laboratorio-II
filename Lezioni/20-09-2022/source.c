//
// Created by Gabriele Scannagatti on 20/09/22.
//
#include<stdio.h>
#include<stdarg.h>

//Esempio di funzione con numero variabile di parametri
double sum(int, ...);

int main(void) {
    printf("%f %f %f \n", sum(2,7.0,3.0), sum(7,1.0,2.0,3.0,4.0,5.0,6.0,7.0), sum(0));
    return 0;
}

double sum(int n, ...){
    double sum = 0;
    va_list args;
    va_start(args, n);
    for(int i = 0; i < n ; i++) {
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum;
}
