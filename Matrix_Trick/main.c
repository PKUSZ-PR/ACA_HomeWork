#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_alg.h"
#define MAX 2048

int A[MAX][MAX] = {0};
int B[MAX][MAX] = {0};
int C[MAX][MAX] = {0};
int TMP[MAX][MAX] = {0};

int N[] = {128, 256, 512, 1024, 2048};
int n[] = {4096, 512, 64, 8, 1};

int n_num = 5, N_num = 5;

int main()
{
    int i = 0, j = 0;
    for(; i < n; i++)
        memset(C, 0, sizeof(int)*MAX);
    int b = 1;
    MatrixMultipleBlock(2,1, A, B, C, TMP);
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
