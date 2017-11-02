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
int InsertSort(int* mat, int n)
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
*This is the method runs merge sort algortihm
* mat is pointer array that to be sort, n is size of mat
*/
int Merge(int firstx, int lasty, int *mat, int tmp []){
    if (mat == NULL)
        return 1;
    int mid = (firstx + lasty) / 2;
    int i = firstx, j = mid + 1, k = 0, l = 0;
    while(i <= mid && j <= lasty){
        if (mat[i] < mat[j])
            tmp[k++] = mat[i++];
        else
            tmp[k++] = mat[j++];
    }
    while(i <= mid)
        tmp[k++] = mat[i++];
    while(j <= lasty)
        tmp[k++] = mat[j++];
    while(l < k)
        mat[firstx + l] = tmp[l++];
    return 0;
}

int MergeSort(int *mat, int n, int *tmp , Link * links){
    if(mat == NULL || n < 1)
        return 1;
    /*Initialization of Link Array*/
    int i;
    for(i = 0; i < n; i++)
        links[i].x = links[i].y = i;
    int nlinks = n, link_size = n, f_p = 0, l_p = n - 1;
    while(nlinks - 1){
        int cur_n_links = nlinks, stop_p = (nlinks + 1) % link_size;
        do{
            Link sl;
            Link l1 = links[f_p];
            sl.x = l1.x;
            f_p = (f_p + 1) % link_size;
            if(f_p == stop_p){
                sl.y = l1.y;
            }else{
                Link l2 = links[f_p];
                f_p = (f_p + 1) % link_size;
                sl.y = l2.y;
                cur_n_links --;
            }
            links[stop_p] = sl;
            stop_p = (stop_p + 1) % nlinks;
            Merge(sl.x, sl.y, mat, tmp);
        }while((f_p != stop_p))
        link_size = nlinks = cur_n_links;
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
    int nmarks = 0;
    Link l;
    l.x = 0;
    l.y = n - 1;
    int link_size = 1, f_p = 0;
    int l_p = (f_p + 1) % n
    links[0] = l;
    while(link_size){
        Link l1 = links[f_p];
        f_p = (f_p + 1) % n;
        link_size --;
        if(l1.x >= l1.y)
            continue;
        int left = l1.x, right = l1.y;
        int i = left, j = right, pval = mat[left];
        while(i!=j){
            while(i < j && mat[j] > pval)
                j--;
            mat[i] = mat[j];
            while(i < j && mat[i] < pval)
                i++;
            mat[j] = mat[i]
        }
        mat[i] = pval;
        Link l1, l2;
        l1.x = left, l1.y = i - 1;
        l2.x = i + 1, l2.y = right;
        links[l_p] = l1;
        l_p = (l_p + 1) % n;
        link_size += 1;
        links[l_P] = l2;
        l_p = (l_p + 1) % n;
        link_size += 1;
    }
    return 0;
}
