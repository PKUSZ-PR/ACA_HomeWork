#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cachetest.h"
//extern int A[];
int f()
{
    return 0;
}
void CacheMemTest(int loop){
    printf("***********************Start Cache Memory Test**********************\n");
    /* Assume that memory of L3 Cache is less then 8MB */
    int A[] = {0};
    int maxmem = 1 << 21;
    srand(time(0))
    int i, j, k;
    for(i = 512; i <= maxmem; i <<= 1){
        clock_t s_t, f_t;
        s_t = clock();
        for(j = 0; j < loop; j++){
            A[j%i] = rand() % 5;
        }
        f_t = clock();
        printf("---------MemSize:%d KB, run time is %f------------\n", (i*4)/1024, f_t-s_t);
    }
    printf("***********************Finish Cache Memory Test**********************\n");
}

void CacheBlockTest(int loop, int n){
    printf("***********************Start Cache Block Test**********************\n");
    /* Assume that block size of cache is less than 512B */
    int maxblock = 124;
    srand(time(0));
    int i, j, k;
    for(i = 2; i <= maxblock; i <<= 1){
        clock_t s_t, f_t;
        s_t = clock();
        for(j = 0; j < n; j++){
            for(k = 0; k < n; k += i){
                A[k] = rand() % 3;
            }
        }
        f_t = clock();
        printf("---------BlockSize:%2d B, run time is %f------------\n", i*4, f_t-s_t);
    }
    printf("***********************Finish Cache Block Test**********************\n");
}

/**
*
* This function can test your cache's set association
*
*/
void CacheLineTest(){
    printf("***********************Start Cache Association Test**********************\n");
    /* Assume that block size of cache is less than 512B */
    int i, j, k;
    srand(time());
    for(i = 2; i <= (1<<8); i<<=1){
        clock_t s_t, f_t;
        s_t = clock();
        for(j = 0; j < n; j += i)
            A[j] = rand() % 3;
        f_t = clock();
        printf("---------Step:%2d B, run time is %f------------\n", i, f_t-s_t);
    }
    printf("***********************Finish Cache Association Test**********************\n");
}

