#include <stdio.h>
#include <stdlib.h>
#include "matrix_alg.h"

#define min(x,y) (((x)<(y))?(x):(y))

/**
* This is a method about matrix multiplication with normal type
* The time complexity is O(n*n*n)
* n is the number of
* parameter of mat1, mat2, rs is a N * N matrix
*/
int MatrixMultiple(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX]){
    if(n < 1)
        return 1;
    /*Initialization*/
    int v = 0;
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
int MatrixMultipleTmp(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]){
    if(n < 1)
        return 1;
    int i, j, k = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            tmp[i][j] = mat2[j][i];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
                rs[i][j] += mat1[i][k] * tmp[j][k];
    return 0;
}
/**
* This is the method that do matrix multiplication with blocks
* The time complexity is O(n*n*n*B*B)
* n columns of matrix
* parameter of mat1, mat2, rs and tmp is a N * N matrix
* B block of matrix
*/
int MatrixMultipleBlock(int n, int B, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]){
    if(n < 1 || B < 1)
        return 1;
    int i, j, k, idx, jdx;
    for(i = 0; i < n; i+=B){
        for(j = 0; j < n; j+=B){
            for(k = 0; k < n; k++){
                for(idx = i; idx < min(i+B, n); idx++){
                    int rst = 0;
                    for(jdx = j; jdx < min(j+B, n); jdx++){
                        rst += mat1[k][jdx] * mat2[jdx][idx];
                    }
                    rs[k][idx] += rst;
                }

            }
        }
    }
    return 0;
}


/*
int MatrixMultipleStrassen(int n, int mat1[][], int mat2[][], int rs[][]){
    if(n < 1)
        return 1;
    Strassen(n, mat1, mat2, rs);
    return 0;
}
*/


