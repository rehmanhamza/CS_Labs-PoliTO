#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10
#define M 100

typedef struct{
  char name[N];
  int x;
  int y;
  char movements[M];
} ROBOT;

int main(){
  ROBOT temp, list[N];

  strcpy(temp.name, "NA");
  strcpy(temp.movements, "NA");
  temp.x = -1;
  temp.y = -1;

  //char str[M+1];

  FILE *file;

  file=fopen("file_trajectories.txt", "r");

  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  int i=0, count=0;
  while(!feof(file)){
    fscanf(file, "%s %d %d %s", list[i].name, &list[i].x, &list[i].y, list[i].movements);
    //printf("herefile\n");
    //sscanf(str, "%s %d %d %s", list[i].name, &list[i].x, &list[i].y, list[i].movements);
    //printf("herefile2\n");

    i++;
  }

  count=i;

  if(fclose(file) != 0){
    perror("Error closing file");
    return EXIT_FAILURE;
  }

  char robot1[N] = "R9cKj", robot2[N] = "rc6Kj";
  int index_of_robot1, index_of_robot2;

  //for(int i=0; i<count; i++){
  //  printf("%s %d %d %s\n", list[i].name, list[i].x, list[i].y, list[i].movements);
  //}

  for(int i=0; i<count; i++){
    if(strcmp(robot1, list[i].name) == 0){
      index_of_robot1 = i;
    }
    if(strcmp(robot2, list[i].name) == 0){
      index_of_robot2 = i;
    }
  }

  int length_robot1, length_robot2;
  length_robot1 = strlen(list[index_of_robot1].movements);
  length_robot2 = strlen(list[index_of_robot2].movements);

  //printf("length_robot1 = %d\nlength_robot2 = %d\n", length_robot1, length_robot2);

  if(length_robot1 > length_robot2){
    printf("robot %s visited most different slots.\n", list[index_of_robot1].name);
  }
  if(length_robot2 > length_robot1){
    printf("robot %s visited most different slots.\n", list[index_of_robot2].name);
  }
}
