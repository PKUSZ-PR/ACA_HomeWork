#include <stdio.h>
#include <stdlib.h>
#include "cachetest.h"
#define N (1 << 28)

int A[N] = {0};

int main()
{

    int loop = 1 << 8;
    int loop_mem = 1 << 20;
    CacheMemTest(loop_mem);
    CacheBlockTest(loop, N);
    CacheLineTest(loop, N);
    return 0;
}
