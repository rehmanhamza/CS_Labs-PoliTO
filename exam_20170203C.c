#include<stdio.h>
#include<stdlib.h>

#define N 5
#define M 10
#define C 2
int main(){
  float measurement[N][M]={0.00};
  float limit_min[M]={0.00};
  float limit_max[M]={0.00};

  FILE *file_measure, *file_limit;

  file_limit = fopen("file_limits.txt", "r");

  if(file_limit == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  for(int i=0; i<M; i++){
    fscanf(file_limit, "%f %f", &limit_min[i], &limit_max[i]);
  }

  fclose(file_limit);

  /*int i=0, j=0;
  while(!feof(file_limit)){
    fscanf(file_limit, "%f", &limits[i][j]);
    i++;
    j++;
  }*/

  for(int i=0; i<M; i++){
      printf("%0.2f %0.2f\n", limit_min[i], limit_max[i]);
  }


  printf("\n\n");

  file_measure = fopen("file_measures.txt", "r");

  if(file_measure == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      fscanf(file_measure, "%f", &measurement[i][j]);
    }
  }

  fclose(file_measure);

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      printf("%0.2f ", measurement[i][j]);
    }
    printf("\n");
  }
  float average[M]={0.0};
  int count=0, max = 5, new_count=0;

  printf("\n\n");

  for(int j=0; j<M; j++){
    for(int i=0; i<N; i++){
      average[j] += measurement[i][j];
    }
    printf("average[%d] = %0.2f\n", j, average[j] / 5);
  }

  for(int i=0; i<M; i++){
      if((average[i] / 5) < limit_min[i] || (average[i] / 5) > limit_max[i]){
        count++; //printf("LIMIT EXCEEDED by sensor %d\n", i);
      }
  }

  new_count = 10 - count;
  if(new_count > max){
    
  }
  printf("\n\nCOUNT = %d\n", new_count);

}
