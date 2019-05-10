#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define N 4

struct coordinate{
  int x;
  int y;
};


int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Wrong number of arguments.\n");
    return EXIT_FAILURE;
  }
  else{
    struct coordinate a[N];
    float distance=0;
    float min=0;

    printf("Enter Coordinates:\n");
    for(int i=0; i<N; i++){
      scanf("%d %d", &a[i].x, &a[i].y);
    }

    for(int i=0; i<N; i++){
      printf("x[%d], y[%d] = %d %d\n", i, i, a[i].x, a[i].y);
    }

    if(strcmp(argv[1], "-m") == 0){
      for(int i=1; i<N; i++){
        distance += (sqrt(pow((a[i].x - a[i-1].x),2) + pow((a[i].y - a[i-1].y),2)));
      }

      printf("Distance = %0.2f\n", distance);
    }
    if(strcmp(argv[1], "-a") == 0){
      int i=1;
      min += (sqrt(pow((a[i].x - a[i-1].x), 2) + pow((a[i].y - a[i-1].y),2)));

      for(int i=2; i<N; i++){
        distance += (sqrt(pow((a[i].x - a[i-1].x),2) + pow((a[i].y - a[i-1].y),2)));
        if(min > distance){
          min=distance;
        }
      }

      printf("Minimum = %0.2f\n", min);
    }
  }

    return EXIT_SUCCESS;
}
