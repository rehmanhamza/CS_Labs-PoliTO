#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20
#define M 10
#define MAX 100

typedef struct{
  int card;
  char date[M];
  char enter_time[M];
  char exit_time[M];
  char birthdate[M];
} MUSEUM;

int main(){
  MUSEUM temp, list[N];

  strcpy(temp.date, "NA");
  strcpy(temp.enter_time, "NA");
  strcpy(temp.exit_time, "NA");
  strcpy(temp.birthdate, "NA");

  temp.card = -1;

  char str[MAX+1];

  FILE *file;

  file=fopen("file_visits.txt", "r");

  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  int i=0, count=0;

  while(fgets(str, MAX, file) != NULL){
    sscanf(str,"%d %s %s %s %s", &list[i].card, list[i].date, list[i].enter_time, list[i].exit_time, list[i].birthdate);

    i++;
  }

  count = i;

  for(int i=0; i<count; i++){
    printf("%d %s %s %s %s\n", list[i].card, list[i].date, list[i].enter_time, list[i].exit_time, list[i].birthdate);
  }
}
