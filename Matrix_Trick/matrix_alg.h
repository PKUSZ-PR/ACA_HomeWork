#ifndef MATRIX_ALG_H_INCLUDED
#define MATRIX_ALG_H_INCLUDED
#define K_SIZE 1024
#define MAX 2048
int MatrixMultiple(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX]);
int MatrixMultipleTmp(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]);
int MatrixMultipleBlock(int n, int B, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]);
int MatrixMultipleSparse(int n, int (*mat1)[MAX], int (*mat2)[MAX], int (*rs)[MAX], int (*tmp)[MAX]);
#endif // MATRIX_ALG_H_INCLUDED
