#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int main(){
  FILE *file, *file_result;
  file=fopen("file1.dat", "r");
  char str[MAX+1+1];
  int x, y, line=1;

  if((file == NULL)){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    file_result=fopen("file2.dat", "w");
    if(file_result == NULL){
      perror("Error in creating file");
      return EXIT_FAILURE;
    }
    else{
      while(fgets(str, MAX, file) != NULL){
        //fprintf(stdout, "%s", str);
        //printf("String Length = %d\n", strlen(str));
        if(sscanf(str, "%d %d", &x, &y) != 2){
          printf("Error - file format error in line %d\n%s\n", line, str);
        }
        else{
        fprintf(file_result, "%d + %d = %d\n", x, y, x+y);
      }
      line++;
    }

      if(fclose(file) != 0){
        perror("Error in closing file");
        return EXIT_FAILURE;
      }
    }
  }

  return EXIT_SUCCESS;

}
