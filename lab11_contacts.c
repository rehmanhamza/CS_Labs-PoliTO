#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3

typedef struct{
  char name[20];
  char surname[20];
  char number[20];
  char mobile[20];
} names;

int main(){
  names temp, list[N];
  strcpy(temp.name, "NA");
  strcpy(temp.surname, "NA");
  strcpy(temp.number, "NA");
  strcpy(temp.mobile, "NA");

  printf("Enter name, surname, number, mobile:\n");
  for(int i=0; i<N; i++){
    scanf("%s %s %s %s", list[i].name, list[i].surname, list[i].number, list[i].mobile);

    for(int j=0; j<i; j++){
      if((strcmp(list[j].name, list[i].name) == 0) || (strcmp(list[j].surname, list[i].surname) == 0)){
        printf("WARNING! DUPLICATE NAME/SURNAME FOUND.\n");
      }
    }
  }

  printf("\n\n\t\t***Contact List***\n");
  for(int i=0; i<N; i++){
    printf("%s %s %s %s\n", list[i].name, list[i].surname, list[i].number, list[i].mobile);
  }

  return EXIT_SUCCESS;
}
