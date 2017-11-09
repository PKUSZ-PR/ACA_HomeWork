#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_alg.h"
/**
*This is the program that compare three kinds of sorting algorithm with metrics of time
*Three are three algorithm, Insertion Algorithm, Merge Algorithm and quick sort
*/
#define K_SIZE 1024
#define MAX_NUM 0x7ffff
#define REPEAT_TIME 10000
/*This is the size of testing file*/
int filesize[] = {1, 4, 16, 64, 256, 1*1024, 4*1024, 16*1024};
int MAX_SIZE = (16*1024 + 100);
int v = 0;
/*Prevent Stack Flow*/
int *tmp;
Link *links;
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

int main()
{
    int i, j, k, v;
    clock_t st, ft;
    int *tmp = (int*)malloc(sizeof(int) * MAX_SIZE);
    memset(tmp, 0,sizeof(int)* MAX_SIZE);
    Link *links = (Link*)malloc(sizeof(Link) * MAX_SIZE);
    for(v = 0; v < MAX_SIZE; v++)
    links[v].x = links[v].y = v;
    printf("*************************Start Insertion Sort*************************\n");
    for(i = 0; i < 8; i++){
        int a_size = filesize[i];
        int *p = RandomArray(a_size);
        st = clock();
        for(j = 0; j < REPEAT_TIME; j++){
            InsertSort(p, a_size);
        }
        ft = clock();
        ft = ft - st;
        free(p);
        printf("Size(K): %7d, Time(ms): %d\n", a_size, (int)ft);
    }
    printf("*************************Finish Insertion Sort*************************\n\n");

    printf("*************************Start Merge Sort*************************\n");
    for(i = 0; i < 8; i++){
        int a_size = filesize[i];
        int *p = RandomArray(a_size);

        for(v = 0; v < a_size; v++)
            links[v].x = links[v].y = v;
        memset(tmp, 0, sizeof(int)*a_size);
        st = clock();
        for(j = 0; j < REPEAT_TIME; j++){
            MergeSort(p, a_size, tmp, links);
        }
        ft = clock();
        ft = ft - st;
        free(p);
        printf("Size(K): %7d, Time(ms): %d\n", a_size, (int)ft);
    }


    printf("*************************Start Quick Sort*************************\n");
    for(i = 0; i < 8; i++){
        int a_size = filesize[i];
        int *p = RandomArray(a_size);
        Link *links = (Link*)malloc(sizeof(Link) * (a_size + 10));
        for(v = 0; v < a_size; v++)
            links[v].x = links[v].y = v;
        st = clock();
        for(j = 0; j < REPEAT_TIME; j++){
            QuickSort(p, a_size, links);
        }
        ft = clock();
        ft = ft - st;
        free(p);
        printf("Size(K): %7d, Time(ms): %d\n", a_size, (int)ft);
    }
    printf("*************************Finish Quick Sort*************************\n\n");
    free(links);
    free(tmp);
    return 0;
}
