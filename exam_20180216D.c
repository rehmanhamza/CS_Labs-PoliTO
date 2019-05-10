#include<stdio.h>
#include<stdlib.h>

#define N 3
#define M 7

int main(){
  char map[2*N][M];

  FILE *file_input;

  file_input = fopen("file_histogram.txt", "r");

  if(file_input == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  for(int i=0; i<2*N; i++){
    fscanf(file_input, "%s", map[i]);
  }

  for(int i=0; i<2*N; i++){
    for(int j=0; j<M; j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  int count[M]={0};

  for(int i=0; i<2*N; i++){
    if(map[i][0] == 'X')
      ++count[0];
    if(map[i][1] == 'X')
      ++count[1];
    if(map[i][2] == 'X')
      ++count[2];
    if(map[i][3] == 'X')
      ++count[3];
    if(map[i][4] == 'X')
      ++count[4];
    if(map[i][5] == 'X')
      ++count[5];
    if(map[i][6] == 'X')
      ++count[6];
    if(map[i][7] == 'X')
      ++count[7];
  }

  int max = -100, index = -1;

  for(int i=0; i<M; i++){
    if(i >= (N+1))
      count[i] *= -1;
    printf("%d ", count[i]);

    if(count[i] > max){
      max = count[i];
      index = i;
    }
  }

  printf("\n\nThe maximum value is %d, in position %d.\n", max, index+1);
}
