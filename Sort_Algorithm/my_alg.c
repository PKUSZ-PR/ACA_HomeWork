#include <stdio.h>
#include <stdlib.h>
#include "my_alg.h"
/**
* This this the method runs insert sort algorithm
* mat is pointer of array that to be sorted
* n is the number of elements
* Time complexity of it is O(n*n)
* Return 0 if sorting is valid o.w return 1
*/
int InsertSort(int* mat, int n){
    if(mat == NULL || n < 1)
        return 1;
    int i, pval = 0;
    for (i = 1; i < n; i++){
        int j;
        pval = mat[i];
        for (j = i - 1; j >= 0; j--){
            if(mat[j] > pval)
                mat[j+1] = mat[j];
            else
                break;
        }
        mat[j+1] = pval;
    }
    return 0;
}
/**
* This is the method runs merge sort algorithm
* mat is pointer array that to be sort, n is size of mat
*/
int Merge(int firstx, int lastx, int firsty, int lasty,  int *mat, int *tmp){
    if (mat == NULL || firstx > lasty)
        return 1;
    int i = firstx, j = firsty, k = 0, l = 0;
    while(i <= lastx && j <= lasty){
        if (mat[i] < mat[j])
            tmp[k++] = mat[i++];
        else
            tmp[k++] = mat[j++];
    }
    while(firstx != firsty & i <= lastx)
        tmp[k++] = mat[i++];
    while(firstx != firsty & j <= lasty)
        tmp[k++] = mat[j++];
    while(l < k){
        mat[firstx + l] = tmp[l];
        l++;
    }
    return 0;
}
/**
*
*
*/
int MergeSort(int *mat, int n, int *tmp , Link *links){
    if(mat == NULL || n < 1)
        return 1;
    /* Initialization of Link Array */
    int i;
    for(i = 0; i < n; i++)
        links[i].x = links[i].y = i;
    int nlinks = n, link_size = n, f_p = 0, l_p = 0, stop_p = 0;
    while(nlinks - 1){
        int cur_n_links = nlinks;
        do{
            Link sl;
            Link sv;
            Link l1 = links[f_p];
            sl.x = l1.x;
            sl.y = l1.y;
            f_p = (f_p + 1) % n;
            if(f_p == l_p){
                sv.x = l1.x;
                sv.y = l1.y;
            }
            else{
                Link l2 = links[f_p];
                f_p = (f_p + 1) % n;
                sv.y = l2.y;
                sv.x = l2.x;
                cur_n_links --;
            }
            links[stop_p] = sl;
            stop_p = (stop_p + 1) % n;
            Merge(sl.x, sl.y, sv.x, sl.x, mat, tmp);
        }while((f_p != l_p));
        nlinks = cur_n_links;
        l_p = stop_p;
    }
    return 0;
}
/**
* This is the method that runs quick sort
* mat is the array that to be sorted
* n is the size of the array
*/
int QuickSort(int *mat, int n, Link *links){
    if(mat == NULL || n < 1)
        return 1;
    /* Initialization */
    Link l;
    l.x = 0;
    l.y = n - 1;
    int link_size = 1, f_p = 0;
    int l_p = (f_p + 1) % n;
    links[0] = l;
    while(link_size){
        Link l = links[f_p];
        f_p = (f_p + 1) % n;
        link_size --;
        if(l.x >= l.y)
            continue;
        int left = l.x, right = l.y;
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
        Link l1, l2;
        l1.x = left, l1.y = i - 1;
        l2.x = i + 1, l2.y = right;
        links[l_p] = l1;
        l_p = (l_p + 1) % n;
        link_size ++;
        links[l_p] = l2;
        l_p = (l_p + 1) % n;
        link_size ++;
    }
    return 0;
}
