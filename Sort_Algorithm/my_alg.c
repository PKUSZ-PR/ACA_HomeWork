#include <stdio.h>
#include <stdlib.h>
#include "my_alg.h"
/**
* This this the method runs insert sort algorithm
* mat is pointer of array that to be sorted
* n is the number of elements
* Time complexity of it is O(n*n)
*/
void* InsertSort(int* mat, int n){
    int i, pval = 0;
    for (i = 1; i < n; i++){
        int j;
        pval = mat[i];
        for (j = i - 1; j >= 0; j--){
            if(mat[j] > pval)
                mat[j+1] = mat[j];
            else
                break;
        }
        mat[j+1] = pval;
    }
}
/**
*This is the method runs merge sort algortihm
* mat is pointer array that to be sort, n is size of mat
*/


