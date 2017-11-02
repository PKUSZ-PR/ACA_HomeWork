#ifndef MY_ALG_H_INCLUDED
#define MY_ALG_H_INCLUDED
#define K_SIZE 1024
/**
* This is the structure that can save indexes of a part of array
* x is the first index an y is the last index
*/
typedef struct {
    int x;
    int y;
}Link;

int InsertSort(int* mat, int n);
int Merge(int firstx, int lasty, int *mat, int tmp []);
int MergeSort(int *mat, int n, int *tmp , Link * links);
int QuickSort(int *mat, int n);
#endif // MY_ALG_H_INCLUDED