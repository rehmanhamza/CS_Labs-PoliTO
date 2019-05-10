#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10

int main(int argc, char *argv[]){
  char number[N+1], date[N+1], start_time[N+1], end_time[N+1], is_friend;
  char input[N+1];
  int month;
  printf("Enter number: ");
  scanf("%s", input);
  printf("Enter month: ");
  scanf("%d", &month);

  FILE *file;

  int hh1, mm1, ss1;
  int hh2, mm2, ss2;
  int hrs = 0, min = 0, sec = 0;
  int total_time = 0;
  float slot1 = 0.23, slot2 = 0.51, slot3 = 0.65, slot4 = 0.12;
  float cost = 0, total_cost = 0;

  file=fopen("file_users.dat", "r");

  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    while(!feof(file)){
      fscanf(file, "%s %s %s %s %c", number, date, start_time, end_time, &is_friend);

      if(strcmp(number, input) == 0){
        int dd, mm, yyyy;
        sscanf(date, "%d/%d/%d", &dd, &mm, &yyyy);
        if(month == mm){

          sscanf(start_time, "%d:%d:%d", &hh1, &mm1, &ss1);
          sscanf(end_time, "%d:%d:%d", &hh2, &mm2, &ss2);

          hrs=(hh2-hh1)*60*60;
          min=(mm2-mm1)*60;
          sec=(ss2-ss1);

          if(hrs < 0){
            hrs *= -1;
          }
          if(min < 0){
            min *= -1;
          }
          if(sec < 0){
            sec *= -1;
          }

          total_time = (hrs+min+sec);

          if(hh1 > 0 && hh1 < 5){
            cost += (slot1*(total_time/30));
          }
          if(hh1 > 5 && hh1 < 11){
            cost += (slot2*(total_time/30));
          }
          if(hh1 > 11 && hh1 < 17){
            cost += (slot3*(total_time/30));
          }
          if(hh1 > 17 && hh1 < 23){
            cost += (slot4*(total_time/30));
          }

          total_cost += cost;

          printf("%0.2f\n", total_cost);
          //printf("hrs = %d, min = %d, sec = %d\ntotal_time = %d\n", hrs, min, sec, total_time);
          //printf("%d:%d:%d\n", hh1, mm1, ss1);
          //printf("%s\n", date);
        }
        //printf("%s %s %s %s %c\n", number, date, start_time, end_time, is_friend);
      }
      //printf("final = %0.2f\n", total_cost);
    }
  }
}
