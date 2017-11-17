#include <stdio.h>
#include <stdlib.h>
#include "matrix_alg.h"
#include "string.h"

#define min(x,y) (((x)<(y))?(x):(y))
#define MAXN 10000

//add to slove sparse matrix of mutiply
typedef struct
{
	int i, j;
	int e;
}Triple;

typedef struct
{
	Triple data[MAXN];
	int rpos[MAX];
	int mu, nu, tu;
}Matrix;

Matrix createMatrix(int (*a)[MAX], int n)
{
	Matrix x;
	x.tu = 0;
	x.mu = n;
	x.nu = n;
	int i, j;
	for(i = 0; i < n; i++)
	{
		int flag = 0;
		for(j = 0; j < n; j++){
			if( a[i][j] ){
				x.data[x.tu].e = a[i][j];
				x.data[x.tu].i = i;
				x.data[x.tu].j = j;
 				if(!flag){
					flag = 1;
					x.rpos[i] = x.tu;
				}
				x.tu++;
			}
		}
		
		if(!flag){
			x.rpos[i] = x.tu;	
		}
	}
	
	return x;
}

/**
* This is a method about matrix multiplication with normal type
* The time complexity is O(n*n*n)
* n is the number of
* parameter of mat1, mat2, rs is a N * N matrix
*/
int MatrixMultiple(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX]){
    if(n < 1)
        return 1;
    /*Initialization*/
    int v = 0;
    for(v = 0; v < n; v++)
        memset(rs[v], 0, sizeof(int) * n);
    int i, j, k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0;k < n; k++)
                rs[i][j] += mat1[i][k] * mat2[k][j];
    return 0;
}

/**
* This is method that can do matrix multiplication using a tempo matrix
* The time complexity is O(n*n*n)
* n columns of matrix
* parameter of mat1, mat2, rs and tmp is a N * N matrix
*/
int MatrixMultipleTmp(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]){
    if(n < 1)
        return 1;
    int i, j, k = 0;
    for(i = 0; i < n; i++)
        memset(rs[i], 0, sizeof(int) * n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            tmp[i][j] = mat2[j][i];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
                rs[i][j] += mat1[i][k] * tmp[j][k];
    return 0;
}
/**
* This is the method that do matrix multiplication with blocks
* The time complexity is O(n*n*n*B*B)
* n columns of matrix
* parameter of mat1, mat2, rs and tmp is a N * N matrix
* B block of matrix
*/
int MatrixMultipleBlock(int n, int B, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]){
    if(n < 1 || B < 1)
        return 1;
    int i, j, k, idx, jdx;
    for(i = 0; i < n; i++)
        memset(rs[i], 0, sizeof(int) * n);
    for(i = 0; i < n; i+=B){
        for(j = 0; j < n; j+=B){
            for(k = 0; k < n; k++){
                for(idx = i; idx < min(i+B, n); idx++){
                    int rst = 0;
                    for(jdx = j; jdx < min(j+B, n); jdx++){
                        rst += mat1[k][jdx] * mat2[jdx][idx];
                    }
                    rs[k][idx] += rst;
                }

            }
        }
    }
    return 0;
}


/**
* This is the method that do matrix multiplication according to sparse matrix
* The time complexity is O(n*n*n)
* n columns of matrix
* parameter of mat1, mat2, rs and tmp is a N * N matrix
* B block of matrix
*/
int MatrixMultipleSparse(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]){
    if(n < 1)
        return 1;
	memset(rs, 0 , sizeof(rs) );
	int ctemp[n], arrow, p, q, s;
	Matrix A = createMatrix(mat1, n);
    Matrix B = createMatrix(mat2, n);
	
	for(arrow = 0; arrow < n; arrow++)
	{
		int tp;
		memset(ctemp, 0, sizeof(ctemp) );

		if(arrow == n-1){
			tp = A.tu;
		}
		else{
			tp = A.rpos[arrow+1];
		}

		for(p = A.rpos[arrow]; p < tp; p++)
		{
			int brow = A.data[p].j, tq;
			if(brow == n-1){
				tq = B.tu;
			}
			else{
				tq = B.rpos[brow+1];
			}

			for(q = B.rpos[brow]; q < tq; q++)
			{
				int ccol = B.data[q].j;
				ctemp[ccol] += A.data[p].e*B.data[q].e;
			}
		}
		
		
		for(s = 0; s < n; s++){
			if(ctemp[s]){
				rs[arrow][s] = ctemp[s];
			}
		}
	}
    return 0;
}



