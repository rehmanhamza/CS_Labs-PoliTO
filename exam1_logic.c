/* Write a program that reads values from .txt file and if sum of any two values equals 42,
exclude those values and copy all other values to another .txt file.
1
10
13
20
32
2
22
17
99
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 9

int main(){
  int a[MAX_LEN+1], jackpot=42, b[MAX_LEN+1]={0};
  FILE *file_read, *file_write;

  file_read=fopen("file_exam1_logic.txt", "r");

  if(file_read==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    int i=0;
    while(!feof(file_read)){
      fscanf(file_read, "%d", &a[i]);
      i++;
    }

    fclose(file_read);

    for(int i=0; i<MAX_LEN; i++){
      for(int j=i; j<MAX_LEN-1; j++){
        if(a[i]+a[j] == jackpot){
          printf("Found at (%d,%d)\n", i+1, j+1);
          a[i]=-1;
          a[j]=-1;
          }
        }
      }

    for(int i=0; i<MAX_LEN; i++){
      if(a[i]==-1){
        continue;
      }
      else{
        b[i]=a[i];
      }
    }

    file_write=fopen("file_exam1_logic_output.txt", "w");
    if(file_write==NULL){
      perror("Error creating file");
      return EXIT_FAILURE;
    }
    else{
      for(int i=0; i<MAX_LEN; i++){
        if(b[i] != 0){
          fprintf(file_write, "%d\n", b[i]);
        }
      }

      fclose(file_write);
    }
  }

  return EXIT_SUCCESS;
}
