#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (1 << 28)
/* The array that used to test */
int A[N] = {0};
/**
*
*
*/
void CacheMemTest(int loop){
    printf("***********************Start Cache Memory Test**********************\n");
    /* Assume that memory of L3 Cache is less then 8MB */
    int maxmem = 1 << 23;
    srand(time(0));
    int i, j, k =0, v;
    for(i = 256; i <= maxmem; i <<= 1){
        int *p = (int*)malloc(sizeof(int)*i);
        for(j = 0; j < i; j++)
            p[j] = rand() % i;
        clock_t s_t, f_t;
        s_t = clock();
        for(j = 0; j < loop; j++){
            if(k == i)
                k = 0;
            v = p[k++];
        }
        f_t = clock();
        double rs = ((f_t - s_t));
        printf("---------MemSize:%7d KB, run time is %f ms------------\n", (i*4)/1024, rs);
        free(p);
    }
    printf("***********************Finish Cache Memory Test**********************\n");
}
/**
*
*
*/
void CacheLineTest(int loop, int n){
    printf("***********************Start Cache line Test**********************\n");
    /* Assume that block size is 64B, then a line of cache can accommodate 16 elements of integer type array */
    int maxstep = 20;
    int i, j, k ,v;
    for(i = 2; i <= maxstep; i+=1){
        clock_t s_t, f_t;
        s_t = clock();
        int idx = 0;
        for(j = 0; j < loop; j++){
            A[(j<<i) & n]++;
        }
        f_t = clock();
        printf("---------Line:%7d , run time is %f ms------------\n", 1<<i, (double)(f_t-s_t));
    }
    printf("***********************Finish Cache line Test**********************\n");
}
/**
*
* This function can test your cache's block size
*
*/
void CacheBlockTest(int loop, int n){
    printf("***********************Start Cache Block Test**********************\n");
    /* Assume that block size of cache is less than 512B */
    int i, j, k;
    srand(time(0));
    for(i = 2; i <= (1<<11); i<<=1){
        clock_t s_t, f_t;
        s_t = clock();
        for(j = 0; j < loop; j += i)
            k = A[j];
        f_t = clock();
        printf("---------BlockSize:%7d B, run time is %f------------\n", i*4, (double)f_t-s_t);
    }
    printf("***********************Finish Cache Block Test**********************\n");
}
int main()
{

    int loop = 1<<8;
    int loop_mem = N;
    int i = 0;
    for(;i < N; i++)
       A[i] = rand() % N;
    CacheLineTest(loop_mem, N);
    //CacheBlockTest(loop, N);
    //CacheLineTest(loop, N);
    return 0;
}
