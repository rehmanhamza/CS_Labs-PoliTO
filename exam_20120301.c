#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 20
#define MAX 40

int main(){
  int date, tdate;
  float amount;
  char str[MAX+1], motivation[MAX_LEN+1], type;

  FILE *file;

  file=fopen("file_today.txt", "r");

  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    //int i=0;
    while(fgets(str, MAX, file) != NULL){
      if(i==0){
        sscanf(str, "%d", &tdate);
      }
      else{
        sscanf(str, "%c %f %s", type, &amount, motivation);
      }
      printf("%d\n", tdate);
      printf("%c %0.2f %s\n", type, amount, motivation);
    }
  }
}
