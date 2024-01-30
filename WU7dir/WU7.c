#include <stdio.h>

// preforms a linear search on an array
int linearSearch(int size,int* arr,int target){
  for(int i=0; i<size; i++) {
    if(*(arr+i)==target){ // if the current index holds our target
      return i; // return that index
    }
  }
  return -1; // return -1 if the target is not in the array
}

int main(){
  int array[]={1, 4, 7, 9, 12};
  int size=sizeof(array)/sizeof(array[0]);
  int target=9; // number we want to search the array for
  int index=linearSearch(size,&array[0],target); // function call
  // print results
  if(index!=-1){
    printf("Element found at index: %d\n",index);
  }else{
    printf("Element not found");
  }
  return 0;
}
