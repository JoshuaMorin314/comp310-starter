/*
I used the following two sources for help no this:
https://www.geeksforgeeks.org/typedef-in-c/
  helped me understand typedef and typedef struct
ChatGPT
  helped me come up with the double pointer idea and how to use malloc()
*/
#include <stdio.h>
#include <stdlib.h>

typedef int type; // if you change this you also need to change the printf command in the printMatrix function to accommodate it

// Define the Matrix structure ()
typedef struct Matrix{
  int r; // number of rows
  int c; // number of columns
  type** e; // element values (pointer to a pointer for dynamic allocation)
} mat;


// initialize the matrix
mat newMatrix(int r,int c){
  mat M;
  M.r=r; // set Matrix.r
  M.c=c; // set Matrix.c
  // set Matrix.e
  M.e=(type**)malloc(r*sizeof(type*)); // allocate memory for the matrix rows
  for(int i=0; i<r; i++){
    M.e[i]=(type*)malloc(c*sizeof(type)); //allocate memory for the matrix elements
  }
  return M;
}

// creates a matrix that mirrors a 2D array
mat setMatrix(int r,int c,type v[r][c]){
  mat M=newMatrix(r,c);
  for(int i=0; i<r; i++){
    // set each element using the contense of v
    for(int j=0; j<c; j++){
      M.e[i][j]=v[i][j];
    }
  }
  return M;
}

// Function to free memory allocated for a Matrix instance
void deleteMatrix(mat* M){
  for(int i=0; i<M->r; i++){
    free(M->e[i]); // free the values (i think)
  }
  free(M->e); // free the pointers to the values (i think)
}

mat addMatrices(mat M0,mat M1){
  mat M;
  if(M0.r!=M1.r || M0.c!=M1.c){
    printf("ERROR: incompatible dimensions \n     The sum of a %dx%d matrix and a %dx%d matrix is undefined.",M0.r,M0.c,M1.r,M1.c);
    return M;
  }
  M=newMatrix(M0.r,M0.c); // initialize sum matrix
  // preform addition
  for(int i=0; i<M.r; i++){
    for(int j=0; j<M.c; j++){
      M.e[i][j]=M0.e[i][j]+M1.e[i][j];
    }
  }
  return M;
}

mat multiplyMatrices(mat M0,mat M1){
  mat M;
  if(M0.c!=M1.r){
    printf("ERROR: incompatible dimensions \n     The product of a %dx%d matrix and a %dx%d matrix is undefined.",M0.r,M0.c,M1.r,M1.c);
    return M;
  }
  M=newMatrix(M0.r,M0.c); // initialize product matrix
  // preform multiplication
  for(int i=0; i<M.r; i++){
    for(int j=0; j<M.c; j++){
      for(int k=0; k<M0.r; k++){
        M.e[i][j]+=M0.e[i][k]*M1.e[k][j];
      }
    }
  }
  return M;
}

void printMatrix(mat M){
  for(int i=0; i<M.r; i++){
    for(int j=0; j<M.c; j++){
      printf("%d ",M.e[i][j]);  // print the element in the ith row and jth column
    }
    printf("\n");
  }
}
