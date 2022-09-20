//
// Created by Gabriele Scannagatti on 15/09/22.
//
#include <stdio.h>
#include "utils.h"

void print_array(int *arr, int size) {
    for(int i = 0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

int bisearch(int key, int* arr, int s, int e) {
    int middle = (e + s)/2;
    if(s>e) return a[e] == key ? e : -1;
    if(arr[middle] == key)
        return middle;
    if(arr[middle] > key)
        return bisearch(key, arr, s, middle);
    else
        return bisearch(key, arr, middle, e)
}
