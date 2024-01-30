#include <stdio.h>

// finds the sum and average of the elements in an array
int main(){
  int nums[]={1,2,3,4,5};  // create array
  int length=sizeof(nums)/sizeof(nums[0]); // length of array
  int sum=0; // running total
  // add all the elements in the array to the running total
  for(int n=0; n<=length; n++){
    sum+=n;
  }
  double avg=sum/length; // calculate the average element value
  // print results
  printf("Sum: %d\n",sum);
  printf("Average: %lf\n",avg);
  return 0;
}
