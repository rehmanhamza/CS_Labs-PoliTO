#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30
#define N 5
#define M 5

typedef struct{
  char surname[MAX+1];
  char name[MAX+1];
  char country[3+1];
  float scores[N][M];
} DATA;

int main(){
  DATA temp, list[N];

  strcpy(temp.surname, "NA");
  strcpy(temp.name, "NA");
  strcpy(temp.country, "NA");
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scores[i][j]=0;
    }
  }

  FILE *file;

  file=fopen("file_gym.txt", "r");

  if(file==NULL){
    perror(Error opening file);
    return EXIT_FAILURE;
  }
  else{
    int i=0;
    while(!feof(file)){
      fscanf(file, "%s %s %s %0.2f %0.2f %0.2f %0.2f %0.2f", list[i].surname, list[i].name, list[i].country, &list[i].scores[i][j], &list[i].scores[i][j+1], &list[i].scores[i][j+2], &list[i].scores[i][j+3], &list[i].scores[i][j+4])
    }
}
