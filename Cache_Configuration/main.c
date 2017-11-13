#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (1 << 28)
#define MB (1 << 20)
#define B (1<<3)
/* The array that used to test */
int A[N] = {0};

/**
*
*
*/
void CacheMemTest(int loop){
    printf("***********************Start Cache Memory Test**********************\n");
    /* Assume that memory of L3 Cache is less then 8MB, block size is 64B*/
    int maxmem = 1 << 23;
    srand(time(0));
    int i, j, k =0;
    volatile int v;
    for(i = 256; i <= maxmem; i <<= 1){
        /*int *p = (int*)malloc(sizeof(int)*i);
        for(j = 0; j < i; j++)
            p[j] = rand() % i;*/
        clock_t s_t, f_t;
        s_t = clock();
        for(j = 0; j < loop; j++){
            v = A[(j<<4) & (i - 1)];
        }
        f_t = clock();
        double rs = ((f_t - s_t));
        printf("---------MemSize:%7d KB, run time is %f ms------------\n", (i*4)/1024, rs);
        ///free(p);
    }
    printf("***********************Finish Cache Memory Test**********************\n");
}
/**
*
*
*/
void CacheMissPenalty(int loop, int n){
    printf("***********************Start Cache MissPenalty Test**********************\n");
    /* Assume that block size is 64B, then a line of cache is 8MB */
    int step = 8*MB/64/B;
    int i, j = 0;
    volatile int v;
     clock_t s_t, f_t;
    s_t = clock();
    for(i = 0; i < loop; i++){
        v = A[j];
        j = (j + step) & (n - 1);
    }
    printf("---------Loop quantity is %d---------\n", loop);
    f_t = clock();
    printf("---------Miss Penalty:%7dms ------------\n", (f_t-s_t) );
    s_t = clock();
    for(i = 0; i < loop; i++){
        v = A[j];
        j = (j + 1) & (15);
    }
    f_t = clock();
    printf("---------Not Miss Penalty:%7dms ------------\n", (f_t-s_t) );
    printf("***********************Finish Cache MissPenalty Test**********************\n");
}
/**
*
* This function can test your cache's block size
*
*/
void CacheBlockTest(int loop, int n){
    printf("***********************Start Cache Block Test**********************\n");
    /* Assume that block size of cache is less than 512B */
    int i, j;
    volatile int k;
    for(i = 2; i <= (1<<11); i<<=1){
        clock_t s_t, f_t;
        s_t = clock();
        for(j = 0; j < loop; j += i)
            k = A[j];
        f_t = clock();
        printf("---------BlockSize:%7d B, run time is %d ms------------\n", i*4, f_t-s_t);
    }
    printf("***********************Finish Cache Block Test**********************\n");
}
int main()
{

    int loop = 1<<28;
    int loop_mem = N;
    int i = 0;
    for(;i < N; i++)
       A[i] = rand() & (N - 1);
    CacheMemTest(loop_mem);
    for(i = 0;i < N; i++)
       A[i] = rand() & (N - 1);
    CacheBlockTest(loop, N);
    for(i = 0;i < N; i++)
       A[i] = rand() & (N - 1);
    CacheMissPenalty(loop, N);
    return 0;
}
