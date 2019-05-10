#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
#define N 10

typedef struct athletes_contest{
  char name[MAX];
  int score;

} contest;

int main(){
  contest temp, list[N];
  char unsorted_list[N][MAX], temp_list[MAX];

  temp.score=0;
  strcpy(temp.name, "NA");

  FILE *file_read, *file_write;
  file_read=fopen("file_contest.txt", "r");

  if(file_read==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    file_write=fopen("file_athletes.txt", "w");
    if(file_write==NULL){
      perror("Error in creating file");
      return EXIT_FAILURE;
    }
    else{
      int i=0;
      while(!feof(file_read) && i<N){
        fscanf(file_read, "%s %d", list[i].name, &list[i].score);
        i++;
      }

      fclose(file_read);

      for(int i=0; i<N; i++){
        strcpy(unsorted_list[i], list[i].name);
      }

      int temp, unsorted_score[N];
      for(int i=0; i<N; i++){
        unsorted_score[i] = list[i].score;
      }

      for(int i=0; i<N-1; i++){
        for(int j=i; j<N; j++){
          if(strcmp(unsorted_list[i], unsorted_list[j]) > 0){
            strcpy(temp_list, unsorted_list[i]);
            strcpy(unsorted_list[i], unsorted_list[j]);
            strcpy(unsorted_list[j], temp_list);

            //sorting scores associated with each player

            temp=unsorted_score[i];
            unsorted_score[i]=unsorted_score[j];
            unsorted_score[j]=temp;

          }
        }
      }

      for(int i=0; i<N; i++){
        printf("%s %d\n", unsorted_list[i], unsorted_score[i]);
        fprintf(file_write, "%s %d\n", unsorted_list[i], unsorted_score[i]);
      }

      printf("\n\n\tBEST THREE POSITIONS\n");
      for(int i=0; i<N; i++){
        for(int j=i; j<N-1; j++){
          if(unsorted_score[i] < unsorted_score[j]){
            temp=unsorted_score[i];
            unsorted_score[i]=unsorted_score[j];
            unsorted_score[j]=temp;

            strcpy(temp_list, unsorted_list[i]);
            strcpy(unsorted_list[i], unsorted_list[j]);
            strcpy(unsorted_list[j], temp_list);

          }
        }
      }

      for(int i=0; i<3; i++){
        printf("%s\n", unsorted_list[i]);
      }
    }
  }
}
