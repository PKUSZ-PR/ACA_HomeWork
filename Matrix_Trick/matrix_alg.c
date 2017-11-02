#include <stdio.h>
#include <stdlib.h>
#include "matrix_alg.h"

/**
* This is a method about matrix multiplication with normal type
* The time complexity is O(n*n*n)
* n is the number of
* parameter of mat1, mat2, rs is a N * N matrix
*/
int MatrixMultiple(int n, int mat1[][], int mat2[][], int rs[][]){
    if(n < 1)
        return 1;
    /*Initialization of matrix of rs*/
    int v = 0;
    while(v < n)
        memset(rs[v++], 0, sizeof(int) * n);
    int i, j, k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0;k < n; k++)
                rs[i][j] += mat1[i][k] * mat2[k][j];
    return 0;
}

/**
* This is method that can do matrix multiplication using a tempo matrix
* The time complexity is O(n*n*n)
* n columns of matrix
* parameter of mat1, mat2, rs and tmp is a N * N matrix
*/
int MatrixMultipleTmp(int n, int mat1[][], int mat2[][], int rs[][], int tmp[][]){
    if(n < 1)
        return 1;
    int i, j, k = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            tmp[i][j] = mat[j][i];
    while(k < n)
        memset(tmp, 0, sizeof(int) * n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
                rs[i][j] += mat1[i][k] * mat2[j][k];
    return 0;
}
/**
* This is the method that do matrix multiplication with blocks
* The time complexity is O(n*n*n)
* n columns of matrix
* parameter of mat1, mat2, rs and tmp is a N * N matrix
* B block of matrix
*/
int MatrixMultipleBlock(int n, int B, int mat1[][], int mat2[][], int rs[][], int tmp[][]){
    if(n < 1 || B < 1)
        return 1;

    return 0;
}

