#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 0x7ffff
#define M 1024*4096*4+10
typedef struct {
    int x;
    int y;
}Link;
typedef struct{
    int fp;
    int lp;
    int y[M];
    int x[M];
}Q;
Q q;
void push(int x, int y, int n){
    q.x[q.lp] = x;
    q.y[q.lp] = y;
    q.lp = (q.lp + 1) & (n - 1);
}
void pop(int*x , int*y, int n){
    (*x) = q.x[q.fp];
    (*y) = q.y[q.fp];
    q.fp = (q.fp + 1) & (n - 1);
}
int mat[M] = {0};
Link link[M] = {0};
int filesize[] = {1, 4, 16, 64, 256, 1*1024, 4*1024, 16*1024};
/**
* This is the method that runs quick sort
* mat is the array that to be sorted
* n is the size of the array
*/
int QuickSort(int *mat, int n){
    if(mat == NULL || n < 1)
        return 1;
    /* Initialization */
    q.fp = 0, q.lp = 1;
    q.x[0], q.y[0] = n -1;
    int n_size = n;
    int x, y;
    while(n_size != 0){
        pop(&x, &y, n);
        if((x) == (y)){
            n_size --;
            continue;
        }else if((x) > (y))
            continue;
        int left = (x), right = (y);
        int i = left, j = right, pval = mat[left];
        while(i!=j){
            while(i < j && mat[j] >= pval)
                j--;
            mat[i] = mat[j];
            while(i < j && mat[i] <= pval)
                i++;
            mat[j] = mat[i];
        }
        mat[i] = pval;
        n_size --;
        if(left <= i-1)
            push(left, i-1, n);
        if(right >= i+1)
            push(i+1, right, n);
    }
    return 0;
}

int main()
{
    int i, j;
    srand(time(0));
    printf("*************************Start Quick Sort*************************\n");
    clock_t st, ft;
    for(i = 0; i < 8; i++){
        int a_size = filesize[i] * 1024;
        for(j = 0; j < a_size; j++)
            mat[j] = rand() % MAX;
        st = clock();
        QuickSort(mat, a_size);
        ft = clock();
        ft = ft - st;
        //free(p);
        printf("Size(K): %7d, Time(ms): %d\n", a_size/ 1024, (int)ft);
    }
    printf("*************************Finish Quick Sort*************************\n\n");
    return 0;
}
