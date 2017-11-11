#ifndef MY_ALG_H_INCLUDED
#define MY_ALG_H_INCLUDED
#define K_SIZE 1024
#define MAX_SIZE ((16*1024 + 100) * K_SIZE)
/**
* This is the structure that can save indexes of a part of array
* x is the first index an y is the last index
*/
typedef struct {
    int x;
    int y;
}Link;
/*
typedef struct{
    int fp;
    int lp;
    int y[MAX_SIZE];
    int x[MAX_SIZE];
}Q;
Q q;
*/
int InsertSort(int* mat, int n);
int Merge(int firstx, int lastx, int firsty, int lasty,  int *mat, int *tmp);
int MergeSort(int *mat, int n, int *tmp , Link * links);
//int QuickSort(int *mat, int n, Link *links);
//int QuickSort(int *mat, int n);
//void pop(int*x , int*y, int n);
//void push(int x, int y, int n);
#endif // MY_ALG_H_INCLUDED
