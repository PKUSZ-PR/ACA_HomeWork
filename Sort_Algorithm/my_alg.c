#include <stdio.h>
#include <stdlib.h>
#include "my_alg.h"

/**
*
*/


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
    int nlinks = n, f_p = 0, l_p = 0, stop_p = 0;
    while(nlinks - 1){
        int cur_n_links = nlinks;
        do{
            Link sl;
            Link sv;
            Link l1 = links[f_p];
            sl.x = l1.x;
            sl.y = l1.y;
            f_p = (f_p + 1) & (n - 1);
            if(f_p == l_p){
                sv.x = l1.x;
                sv.y = l1.y;
            }
            else{
                Link l2 = links[f_p];
                f_p = (f_p + 1)  & (n - 1);
                sv.y = l2.y;
                sv.x = l2.x;
                cur_n_links --;
            }
            links[stop_p].x = sl.x;
            links[stop_p].y = sv.y;
            stop_p = (stop_p + 1)  & (n - 1);
            Merge(sl.x, sl.y, sv.x, sv.y, mat, tmp);
        }while((f_p != l_p));
        nlinks = cur_n_links;
        l_p = stop_p;
    }
    return 0;
}

/*
int QuickSort(int *mat, int n, Link *links){
    if(mat == NULL || n < 1)
        return 1;
    ///Initialization
    int link_size = 1, f_p = 0;
    int l_p = (f_p + 1) & (n - 1);
    links[0].x = 0;
    links[0].y = n - 1;
    int n_size = n;
    while(n_size != 0){
        Link l = links[f_p];
        f_p = (f_p + 1) & (n - 1);
        link_size --;
        if(l.x == l.y){
            n_size --;
            continue;
        }else if(l.x > l.y)
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
        n_size --;
        links[l_p].x = left, links[l_p].y = i - 1;
        l_p = (l_p + 1) & (n - 1);
        links[l_p].x = i + 1, links[l_p].y = right;
        l_p = (l_p + 1) & (n - 1);
        link_size += 2;
    }
    return 0;
}
*/
/*
int QuickSort(int *mat, int n){
    if(mat == NULL || n < 1)
        return 1;
    //Initialization
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
*/
