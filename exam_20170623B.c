#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 6
#define M 5
#define MAX 20

typedef struct{
  char bus[M];
  int route;
  int x;
  int y;
  int time;
} BUS;

int main(){
  BUS temp, list[N];

  strcpy(temp.bus,"NA");
  temp.route=0;
  temp.x=0;
  temp.y=0;
  temp.time=0;

  char str[MAX+1];
  int pos_x[N], pos_y[N];

  FILE *file;

  file=fopen("file_bus.txt", "r");

  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    int i=0;
    while(!feof(file)){
      fscanf(file, "%d %d %d %d %d", &list[i].bus, &list[i].route, &list[i].x, &list[i].y, &list[i].time);

      pos_x[i]=list[i].x;
      pos_y[i]=list[i].y;
      //printf("%d %d %d %d %d\n", list[i].bus, list[i].route, list[i].x, list[i].y, list[i].time);

      i++;
    }

    for(int i=0; i<N; i++){
      printf("(%d,%d)\n", pos_x[i], pos_y[i]);
      //printf("%d %d %d %d %d\n", list[i].bus, list[i].route, list[i].x, list[i].y, list[i].time);
    }
  }
}
