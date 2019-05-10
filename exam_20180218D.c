#include<stdio.h>
#include<stdlib.h>

#define N 5
#define R 6

int main(){
  float map[N][N];
  int x[R], y[R];
  int x_axis, y_axis;
  float weights[R];
  float max_weight, pressure;
  float weight = 0;

  FILE *file_1, *file_2;

  file_1=fopen("file_map_sea.txt", "r");

  if(file_1 == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        fscanf(file_1, "%f", &map[i][j]);
      }
    }
  }

  fclose(file_1);

  /*for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      printf("%0.2f ", map[i][j]);
    }
    printf("\n");
  }*/

  file_2=fopen("file_findings.txt", "r");

  if(file_2 == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<R; i++){
      fscanf(file_2, "%d %d %f", &x[i], &y[i], &weights[i]);
    }
  }

  fclose(file_2);

  for(int i=0; i<R; i++){
      printf("%d %d %0.2f", x[i], y[i], weights[i]);
      printf("\n");
  }

  int dive = 0;

  printf("Enter pressure and weight: ");
  scanf("%f %f", &pressure, &max_weight);

  for(int i=0; i<R; i++){
    x_axis=x[i];
    y_axis=y[i];
    if(x_axis > 5 || x_axis < 0 || y_axis > 5 || y_axis < 0){
      printf("Following points are not recoverable: (%d,%d)\n", x_axis, y_axis);
    }
    if(map[x_axis][y_axis] > pressure){
      printf("Excessive pressure at point: (%d, %d)\n", x_axis, y_axis);
    }

    if(weights[i] > max_weight){
      printf("Excessive weight.\n");
    }
    else{
      weight += weights[i];
      if(weight > max_weight){
        dive++;
        weight = weights[i];
      }
      printf("Dive %d: %d %d\n", dive, x_axis, y_axis);
    }
  }

  // dive can go upto max. weight, for weight greater than max. weight will need more than 1 dive
}
