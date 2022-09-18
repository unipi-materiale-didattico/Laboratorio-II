//
// Created by Gabriele Scannagatti on 15/09/22.
//

/**
 * This macro return the size of the given array
 * @param a
 */
#define sizeOfArr(a) (int)(sizeof(a) / sizeof((a)[0]))

/**
 * This function print array values
 * @param arr the array to print
 * @param size the length of the array
 */
void print_array(int* arr, int size);
