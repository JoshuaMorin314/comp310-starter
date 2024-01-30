#include <stdio.h>
//#include "matrix.c"

typedef int type; // if you change this you also need to change the printf command in the printMatrix function to accommodate it
// Define the Matrix structure ()
typedef struct Matrix{
  int r; // number of rows
  int c; // number of columns
  type** e; // element values (pointer to a pointer for dynamic allocation)
} mat;
mat newMatrix(int r,int c);
mat setMatrix(int r,int c,type v[r][c]);
void deleteMatrix(mat* M);
mat addMatrices(mat M0,mat M1);
mat multiplyMatrices(mat M0,mat M1);
void printMatrix(mat M);

int main(){
  int matrix1[2][2]={{1,2},{3,4}};
  int matrix2[2][2]={{5,6},{7,8}};
  mat M1=setMatrix(2,2,matrix1);
  mat M2=setMatrix(2,2,matrix2);

  mat sum=addMatrices(M1,M2);
  mat product=multiplyMatrices(M1,M2);

  printf("Matrix Addition:\n");
  printMatrix(sum);
  printf("Matrix Multiplication:\n");
  printMatrix(product);
  return 0;
}
