#include<stdio.h>
#include<stdlib.h>

#define MAX 30

typedef struct{
  char surname[MAX+1];
  char name[MAX+1];
  char country[3+1];
  float score;
  float final_score;
} COMPETITOR;

typedef struct{
  char name[3+1];
  float score;
} COUNTRIES;

int main(){
  COMPETITOR podium[3], temp;
  COUNTRIES list[20];
  float temp_score[5], min, max;

  FILE *file;

  file=fopen("file_gym.txt", "r");

  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<3; i++){
      podium[i].score=0.0;
    }

    int i=0;
    while(!feof(file)){
      if(fscanf(file, "%s %s %s %0.2f %0.2f %0.2f %0.2f %0.2f", temp.surname, temp.name, temp.country, &temp_score[0], &temp_score[1], &temp_score[2], &temp_score[3], &temp_score[4]) != 8);
        printf("Error! \n");
      min=temp_score[0];
      max=temp_score[0];
      temp.final_score=0;

      for(int i=0; i<5; i++){
        temp.final_score += temp_score[i];

        if(temp_score[i] < min){
          min=temp_score[i];
        }

        if(temp_score[i] > max){
          max=temp_score[i];
        }
      }
      temp.final_score = temp.final_score - min - max;
    }

    printf("temp.final_score = %0.2f\n", temp.final_score);

  }
}
