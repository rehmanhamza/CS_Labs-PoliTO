#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define N 4

int main(int argc, char *argv[]){
  int x[N], y[N], x0=0, y0=0;
  float distance;
  for(int i=2; i<argc; i++){
    sscanf(argv[i], "%d,%d", &x[i-2], &y[i-2]);
  }

  /*for(int i=0; i<argc-2; i++){
    printf("x[%d],y[%d] = (%d,%d)\n", i, i, x[i], y[i]);
  }*/


  if(strcmp(argv[1], "-m") == 0){
    for(int i=1; i<N; i++){
      x0 += (x[i]-x[i-1]);
      y0 += (y[i]-y[i-1]);
    }
    distance=(sqrt(pow(x0,2)+(pow(y0,2))));
    printf("Distance = %0.2f\n", distance);
  }
  else if(strcmp(argv[1], "-a") == 0){
    int i=1;
    float min;
    min = (sqrt(pow(x[i]-x[i-1],2)+(pow(y[i]-y[i-1],2))));
    for(int i=2; i<N; i++){
      distance = (sqrt(pow(x[i]-x[i-1],2)+(pow(y[i]-y[i-1],2))));
      if(min > distance){
        min = distance;
      }
    }

    printf("Minimum Distance  = %0.2f\n", min);
  }
  else{
    perror("Wrong arguments");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
