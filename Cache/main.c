#include "stdio.h"
#include <stdlib.h>
#include <time.h>

int timediff(clock_t t1, clock_t t2) {
    int elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}
int array[1<<20];
int test(int array_size){
    int array_size=1<<20;
    int repeat_times = 10000000;

    for(int i=0; i<array_size; i++){
        array[i] = 0;
    }
    int j=0;
    int k=0;
    int c=0;
    clock_t start=clock();
    while(j++<repeat_times){
        if(k==array_size){
            k=0;
        }
        c = array[k++];
    }
    clock_t end =clock();
    printf("%lu\n", timediff(start,end));
}
int main(int argc, char *argv[])

{


    return 0;
}
