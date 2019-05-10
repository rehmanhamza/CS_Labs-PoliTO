#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define N 4

int main(int argc, char *argv[]){
  int x0=0, y0=0, x[N]={1,3,5,7}, y[N]={2,4,6,8};
  float distance;
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
