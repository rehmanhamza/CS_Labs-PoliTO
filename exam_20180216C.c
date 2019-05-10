#include<stdio.h>
#include<stdlib.h>

#define N 11


int main(){
  char map[N][N];

  FILE *file;

  file=fopen("file_bath.txt", "r");

  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<N; i++){
      fscanf(file, "%s", map[i]);
    }
  }

  fclose(file);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  int x, y, count=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(map[i][j] == '2'){
        //printf("(%d,%d)\n", i, j);
        x=i;
        y=j;

        for(int k=x; k>=0 && map[y][k] == '+'; k--){
          count++;//for(int l=y; l<N; l++)
        }
        for(int k=x+1; k<N && map[y][k] == '+'; k++){
          count++;
        }
        for(int l=y; l>=0 && map[l][x] == '+'; l--){
          count++;
        }
        for(int l=y+1; l<N && map[l][x] == '+'; l++){
          count++;
        }
      }
    }
  }

  printf("Count = %d\n", count);
}
