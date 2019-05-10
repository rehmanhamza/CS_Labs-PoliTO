#include<stdio.h>
#include<stdlib.h>

#define N 4
#define M 3

int main(){
  int a[N][M];//={{-12, -2, 34}, {34, 56, -2},{18,-32, 18},{-2, 56, -23}};
  FILE *file;

  file=fopen("file_occur.txt", "r");

  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        fscanf(file, "%d", &a[i][j]);
      }
    }

    fclose(file);

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }

    printf("\n\n");

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        for(int k=0; k<N; k++){
          for(int l=0; l<M; l++){
            if(a[i][j] == a[k][l]){
              if(i != k || j != l){
                printf("%d(%d,%d) : %d(%d,%d)\n", a[i][j], i, j, a[k][l], k, l);
              }
            }
          }
        }
      }
    }
  }
}
