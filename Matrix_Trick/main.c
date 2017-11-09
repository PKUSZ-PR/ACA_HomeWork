#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_alg.h"
#define MAX 2048
#define DIV 3

int A[MAX][MAX] = {0};
int B[MAX][MAX] = {0};
int C[MAX][MAX] = {0};
int TMP[MAX][MAX] = {0};

int N[] = {128, 256, 512, 1024, 2048};
int n[] = {4096, 512, 64, 8, 1};

int n_num = 5;

int main()
{
    /*Initialization*/
    int i = 0, j = 0;
    int b = 16;
    clock_t st, ft;
    srand(time(0));
    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            A[i][j] = rand()% DIV, B[i][j] = rand() % DIV;
    /*Start testing*/

    printf("*************************Start MatrixMultiple*************************\n");
    for(i = 0; i < n_num; i++){
        int NN = N[i], nn = n[i];
        st = clock();
        for(j = 0; j < nn; j++){
            MatrixMultiple(NN, A, B, C);
            MatrixMultiple(NN, A, B, B);
            MatrixMultiple(NN, B, C, A);
        }
        ft = clock() - st;
        printf("N=%4d, n=%4d, time(ms)=%d\n", NN, nn, ft);
    }
    printf("*************************Finish MatrixMultiple*************************\n\n");

    printf("*************************Start MatrixMultipleTmp*************************\n");
    for(i = 0; i < n_num; i++){
        int NN = N[i], nn = n[i];
        st = clock();
        for(j = 0; j < nn; j++){
            MatrixMultipleTmp(NN, A, B, C, TMP);
            MatrixMultipleTmp(NN, A, B, B, TMP);
            MatrixMultipleTmp(NN, B, C, A, TMP);
        }
        ft = clock() - st;
        printf("N=%4d, n=%4d, time(ms)=%d\n", NN, nn, ft);
    }
    printf("*************************Finish MatrixMultipleTmp*************************\n\n");

    printf("*************************Start MatrixMultipleBlock*************************\n");
    for(i = 0; i < n_num; i++){
        int NN = N[i], nn = n[i];
        st = clock();
        for(j = 0; j < nn; j++){
            MatrixMultipleBlock(NN, b, A, B, C, TMP);
            MatrixMultipleBlock(NN, b, A, B, B, TMP);
            MatrixMultipleBlock(NN, b, B, C, A, TMP);
        }
        ft = clock() - st;
        printf("N=%4d, n=%4d, time(ms)=%d\n", NN, nn, ft);
    }
    printf("*************************Finish MatrixMultipleBlock*************************\n\n");

    printf("*************************Start MatrixMultipleSparse*************************\n");
    for(i = 0; i < n_num; i++){
        int NN = N[i], nn = n[i];
        st = clock();
        for(j = 0; j < nn; j++){
            MatrixMultipleSparse(NN, A, B, C, TMP);
            MatrixMultipleSparse(NN, A, B, B, TMP);
            MatrixMultipleSparse(NN, B, C, A, TMP);
        }
        ft = clock() - st;
        printf("N=%4d, n=%4d, time(ms)=%d\n", NN, nn, ft);
    }
    printf("*************************Finish MatrixMultipleSparse*************************\n\n");

    return 0;
}
