#include <stdio.h>

int main(int argc,char ** argv){
  double num1,num2; // initialize numbers
  // ask for input from the user
  printf("Enter first number: ");
  scanf("%lf",&num1);
  printf("Enter second number: ");
  scanf("%lf",&num2);

  // print calculations
  printf("Sum: %lf\n",(num1+num2));
  printf("Difference: %lf\n",(num1-num2));
  printf("Product: %lf\n",(num1*num2));
  printf("Quotient: %lf\n",(num1/num2));
  return 0;
}
