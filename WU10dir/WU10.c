#include <stdio.h>
#include <stdlib.h>

// prints back anything added to the command line when the prigram is run
int main(int argc,char ** argv){
  for(int i=1; i<argc; i++){ // for every element in argv
    printf("i=%d argv[%d] = %s\n",i,i,argv[i]);
  }
  return 0;
}
