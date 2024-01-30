#include <stdio.h>

int main(){
  int nums[]={1,2,3,4,5};
  int length=sizeof(nums)/sizeof(nums[0]);
  int sum=0;
  for(int n=0; n<=length; n++){
    sum+=n;
  }
  double avg=sum/length;
  printf("Sum: %d\n",sum);
  printf("Average: %lf\n",avg);
  return 0;
}
