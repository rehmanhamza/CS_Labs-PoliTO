#include<stdio.h>
#include<stdlib.h>

#define N 9
#define M 3

void check_pattern(int map[][N], int pattern[][M], int i, int j);
int main(){
  int map[N][N];
  int pattern[M][M];

  FILE *file_1, *file_2;

  file_1=fopen("file_map1.txt", "r");

  if(file_1==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        fscanf(file_1, "%d", &map[i][j]);
      }
    }
  }

    fclose(file_1);

    /*for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        printf("%d ", map[i][j]);
      }
      printf("\n");
    }*/


  file_2=fopen("file_pattern1.txt", "r");

  if(file_2==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<M; i++){
      for(int j=0; j<M; j++){
        fscanf(file_2, "%d", &pattern[i][j]);
      }
    }
  }

  fclose(file_2);

  printf("\n\n");

  for(int i=0; i<M; i++){
    for(int j=0; j<M; j++){
      printf("%d ", pattern[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(map[i][j] == 93){
        printf("\n93 found at (%d,%d).\n", i+1, j+1);

        check_pattern(map, pattern, i, j);
      }
    }
  }
}

void check_pattern(int map[][N], int pattern[][M], int i, int j){

  for(int a=i, k=0; a<N; a++, k++){
    for(int b=j, l=0; b<N; b++, l++){
      if(map[a][b] == pattern[k][l]){
        printf("%d ", map[a][b]);

      }
    }
  }

}
