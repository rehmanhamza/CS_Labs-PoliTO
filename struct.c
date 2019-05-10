#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct student_info{
  char last_name[MAX+1];
  char name[MAX+1];
  int id;
  int mark;

} STUDENTS;

int main(int argc, char *argv[]){
  STUDENTS temp, list[100];
  FILE *file;

  temp.id=0;
  temp.mark=0;
  strcpy(temp.name, "NA");
  strcpy(temp.last_name, "NA");

  if(argc != 2){
    printf("Wrong number of arguments.\n");
    return EXIT_FAILURE;
  }

  file=fopen(argv[1], "r");
  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    int i=0, count;
    while(!feof(file)){
      fscanf(file, "%s %s %d %d", list[i].last_name, list[i].name, &list[i].id, &list[i].mark);
      //printf("%s %s %d %d\n", list[i].last_name, list[i].name, list[i].id, list[i].mark);

      i++;
    }
    count=i;

    for(int i=0; i<count-1; i++){
      printf("%d %d\n", list[i].id, list[i].mark);
    }

    fclose(file);
  }
  //printf("ID: %d MARK: %d LN: %s N: %s\n", temp.id, temp.mark, temp.name, temp.last_name);

  return EXIT_SUCCESS;
}
