//
// Created by Gabriele Scannagatti on 13/10/22.
//
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_STR_LEN 100

int strcmpWrap(const void*, const void*);
//Array di stringhe da ordinare in modo lessicografico
int main(void){
    int n; // Numero stringhe
    scanf("%d", &n);
    char *strArr[n];
    for(int i=0; i<n; i++){
        strArr[i] = (char*)malloc(MAX_STR_LEN*sizeof(char));
        if(strArr[i] == NULL)
            exit(EXIT_FAILURE);
        scanf("%s", strArr[i]);
    }
    qsort(strArr, n, sizeof(char*), strcmpWrap);
    printf("Ordinate:\n");
    for(int i=0; i<n; i++){
        printf("%s\n", strArr[i]);
        free(strArr[i]);
    }
    return EXIT_SUCCESS;
}

int strcmpWrap(const void* str1, const void* str2){
    return strcmp(*(const char**)str1, *(const char**)str2);
}
