#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_alg.h"
/**
*This is the program that compare three kinds of sorting algorithm with metrics of time
*Three are three algorithm, Insertion Algorithm, Merge Algorithm and quick sort
*/
#define K_SIZE 1024
#define MAX_NUM 0x7ffff
/*This is the size of testing file*/
int filesize[] = {1, 4, 16, 64, 256, 1*1024, 4*1024, 16*1024};

/**
* Generate random array which is int type
*/
int* RandomArray(int num){
    int *p = malloc(sizeof(int) * num * K_SIZE);
    memset(p, 0, sizeof(int) * num * K_SIZE);
    srand(time(0));
    int i = 0;
    for (; i < num * K_SIZE; i++)
        p[i] = rand() % MAX_NUM;
    return p;
}

int test[11] = {82,123,42,16,48,33,22,1,56,56, 56};

int main()
{
    Link l[10] = {(0, 0)};
    int tmp[10] = {0};
    MergeSort(test, 10, tmp, l);
    int i = 0;
    for(; i < 11; i++)
        printf("%d ", test[i]);
    return 0;
}
