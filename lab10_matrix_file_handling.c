#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 5

int main(){
  int a[N][N], flag=false, flag1=false;
  FILE *file;

  file=fopen("file_matrix.dat", "r");

  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    printf("File opened successfully.\n\nReading from file...\n\n");
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        fscanf(file, "%d", &a[i][j]);
      }
    }

    printf("Data successfully read from file.\n\n");
    if(fclose(file) != 0){
      perror("Error closing file");
      return EXIT_FAILURE;
    }
    else{
      printf("File closed successfully.\n\n");
    }
    printf("Data read from file: \n");
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
    printf("\n\n");
    
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
          if(((a[i][j] == 0) && (a[i][j+1] == 0) && (a[i][j+2] == 0))){
            flag=true;
            if(flag){
              printf("The sequence is found in the row %d.\n", i+1);
            }
          }
          if(((a[i][j] == 0) && (a[i+1][j] == 0) && (a[i+2][j] == 0))){
            flag1=true;
            if(flag1){
              printf("The sequence is found in the column %d.\n", j+1);
            }
          }
        }
      }
    }

    return EXIT_SUCCESS;
}
