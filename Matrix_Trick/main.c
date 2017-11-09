#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_alg.h"
#define K_SIZE 1024
#define N 2048
int filesize[] = {128, 256, 512, 1024, 2048};
int A[N][N], B[N][N], C[N][N];

int main(){
    /*Initialization*/
    srand(time(0));
    int i, j, k;
    for(i = 0; i < N, i++){
        for(j = 0; j < N; j++){
            A[i][j] = rand() % 5 + 1;
            B[i][j] = rand() % 5 + 1;
            C[i][j] = rand() % 5 + 1;
        }
    }


    return 0;
}
