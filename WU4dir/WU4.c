#include <stdio.h>
#include <string.h>

// reverses a string
int main(){
  char str[]="Hello"; // string to be reversed
  int length=strlen(str)-1; // string length
  char temp;
  //switch the ith and ith from last letter
  for(int i=0; i<length/2; i++){
    temp=str[length-i];
    str[length-i]=str[i];
    str[i]=temp;
  }
  printf("%s\n",str);
  return 0;
}
