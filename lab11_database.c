#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define N 5
#define MAX 20
#define MAX_LEN 40

typedef struct{
  char surname[MAX];
  char name[MAX];
  int id;
  int score;
} database;

int main(){
  database temp, list[N];

  strcpy(temp.surname, "NA");
  strcpy(temp.name, "NA");
  temp.id=0;
  temp.score=0;

  char surname[MAX], name[MAX], str[MAX_LEN], turn, file_name[MAX];
  int id, score, i=0, count=0;
  FILE *file_write;

  while(count != N){
    printf("Enter Command: ");
    gets(str);

    sscanf(str, "%c %s %s %d %d", &turn, surname, name, &id, &score);

    if(turn == 'I' || turn == 'i'){
      strcpy(list[i].surname, surname);
      strcpy(list[i].name, name);
      list[i].id=id;
      list[i].score=score;

      i++;
    }

    count=i;

    if(turn == 'D' || turn == 'd'){
      if(i <= 0){
        printf("Nothing in database...\n");
        return EXIT_FAILURE;
      }
      else{
        sscanf(str, "%c %d", &turn, &id);
        for(int i=0; i<count; i++){
          if((strcmp(list[i].surname, surname) == 0)  || list[i].id == id){
            strcpy(list[i].surname, "NA");
            strcpy(list[i].name, "NA");
            list[i].id=-1;
            list[i].score=-1;
          }
        }
      }
    }

    if(turn == 'V' || turn == 'v'){
      if(i<=0){
        printf("Nothing in database...\n");
        return EXIT_FAILURE;
      }
      else{
        sscanf(str, "%c %d", &turn, &id);
        for(int i=0; i<count; i++){
          if((strcmp(list[i].surname, surname) == 0) || list[i].id == id){
            printf("%s %s %d %d\n", list[i].surname, list[i].name, list[i].id, list[i].score);
          }
        }
      }
    }

    if(turn == 'P' || turn == 'p'){
      for(int i=0; i<count; i++){
        printf("%s %s %d %d\n", list[i].surname, list[i].name, list[i].id, list[i].score);
      }
    }
  }

  if(turn == 'S' || turn == 's'){
    sscanf(str, "%c %s", &turn, file_name);

    printf("\nSaving data into .txt file...\n");

    file_write=fopen(file_name, "w");

    if(file_write==NULL){
      printf("Error creating file.\n");
      return EXIT_FAILURE;
    }
    else{
      for(int i=0; i<N; i++){
        fprintf(file_write, "%s %s %d %d\n", list[i].surname, list[i].name, list[i].id, list[i].score);
      }
    }
    fclose(file_write);

    Sleep(20);
    printf("File Saved.\n");
  }

  if(count == N){
    printf("LIMIT REACHED! CAN'T ADD MORE.\n");
  }

  return EXIT_SUCCESS;
}
