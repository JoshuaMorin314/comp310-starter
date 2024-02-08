/*
I used the following websites for help:
  https://www.geeksforgeeks.org/c-fopen-function-with-examples/
    help understanding fopen(), fprintf(), and fclose()
  https://www.geeksforgeeks.org/fgets-gets-c-language/?ref=lbp
    help understanding fgets()
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  const char *filename="example.txt";

  // Writing to file
  FILE *fw=fopen(filename,"w"); // open the file and tie it to a variable (write only mode)
  if(fw==NULL){
    printf("Error opening file"); // error message if the file was not found
    return 1; // end function in response to the error
  }
  fprintf(fw,"Hello, World!"); // write to the file
  fclose(fw); // close the file

  // Reading from file
  FILE *fr=fopen(filename,"r"); // open the file and tie it to a variable (read only mode)
  if(fr==NULL){
    printf("Error opening file"); // error message if the file was not found
    return 1; // end function in response to the error
  }
  char line[100]; // Assuming a maximum line length of 100 characters (arbitrary)
  while(fgets(line,sizeof(line),fr)!=NULL){ // if the line we load has content
    printf("%s",line); // print the content of the line
  }
  fclose(fr); // close the file

  printf("\n");

  return 0;
}
