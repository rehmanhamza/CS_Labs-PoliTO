#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 128
#define MAXC 20

int main(){
  FILE *file;
  char str[MAX_LEN+1], str1[MAXC], str2[MAXC], str3[MAXC], str4[MAXC], input[MAXC];

  printf("Enter a Train Station: ");
  scanf("%s", input);

  file=fopen("lab9_train.dat", "r");

  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    while(fgets(str, MAX_LEN, file) != NULL){
      sscanf(str, "%s %s %s %s", str1, str2, str3, str4);

      if((strcmp(input, str1)==0) || (strcmp(input, str3)==0)){
        printf("%s %s %s %s\n", str1, str2, str3, str4);
      }
    }

    if(fclose(file) != 0){
      perror("Error in closing file");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
