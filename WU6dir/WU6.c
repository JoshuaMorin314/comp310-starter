#include <stdio.h>

// calculates the factorial of n
int factorial(int n){
  if(n<=0){
    return 1; // 0! is 1
  }else{
    return n*factorial(n-1); // recursive call and return statement
  }
}

int main(){
  int num=5;
  printf("Factorial of %d is: %d\n",num,factorial(num));
  return 0;
}
