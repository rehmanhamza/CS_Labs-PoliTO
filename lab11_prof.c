#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3
#define MAX 20
#define MAX_LEN 50

typedef struct{
  char subject[MAX+1];
  char name[MAX+1];
  char surname[MAX+1];
  int period;
  int credits;
  float percentage;
} PROF;

int main(){
  PROF temp, list[N];
  char str[MAX_LEN+1];

  strcpy(temp.subject, "NA");
  strcpy(temp.name, "NA");
  strcpy(temp.surname, "NA");
  temp.period=0;
  temp.credits=0;
  temp.percentage=0.0;

  FILE *file;

  file=fopen("file_prof.txt", "r");

  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    int i=0;
    while(fgets(str, MAX_LEN, file) != NULL){
      sscanf(str, "%s %s %s %d %d %f", list[i].subject, list[i].name, list[i].surname, &list[i].period, &list[i].credits, &list[i].percentage);

      i++;
    }

    int maxCredits = -180;
    int pass_rate = 100;
    char max_credit_subject[MAX+1];
    char diff_subject[MAX+1];
    char prof_surname[MAX+1];

    for(int i=0; i<N; i++){
      if(list[i].credits > maxCredits){
        maxCredits = list[i].credits;
        strcpy(max_credit_subject, list[i].subject);
      }
      if(list[i].percentage < pass_rate){
        pass_rate = list[i].percentage;
        strcpy(diff_subject, list[i].subject);
      }
    }

    printf("Max_Credit subject is %s with credits %d.\n", max_credit_subject, maxCredits);
    printf("Difficult subject to pass is %s with pass_rate %d.\n", diff_subject, pass_rate);

    printf("Enter Professor Surname: ");
    scanf("%s", prof_surname);

    for(int i=0; i<N; i++){
      if(strcmp(prof_surname, list[i].surname) == 0){
        printf("%s %s %d %0.2f\n", list[i].surname, list[i].name, list[i].credits, list[i].percentage);
      }
    }
  }
}
