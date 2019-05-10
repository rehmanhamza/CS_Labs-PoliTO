#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10
#define MAX 50

typedef struct{
  int gate;
  int ID;
  int flag;
  int hh;
  int mm;
  int ss;
} BUILDING;

int main(int argc, char *argv[]){
  BUILDING list[N];
  char str[MAX+1];

  if(argc-1 != 1){
    perror("Invalid number of arguments");
    return EXIT_FAILURE;
  }

  FILE *file;

  file=fopen("file_database1.txt", "r");

  if(file == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  int i=0, limit=0;
  while(fgets(str, MAX, file) != NULL){
    sscanf(str, "%d %d %d %d:%d:%d", &list[i].gate, &list[i].ID, &list[i].flag, &list[i].hh, &list[i].mm, &list[i].ss);

    i++;
  }

  limit = i;

  /*for(int i=0; i<limit; i++){
    printf("%d %d %d %d:%d:%d\n", list[i].gate, list[i].ID, list[i].flag, list[i].hh, list[i].mm, list[i].ss);
  }*/

  //printf("\n\n");

  //if(strcmp(argv[1], "-v") == 0){

    int t_hh=0, t_mm=0, t_ss=0, total_time[N], count=0, k=0, id[N], hh[N], mm[N], ss[N];

    for(int i=0; i<limit-1; i++){
      for(int j=i+1; j<limit; j++){
        if(list[i].ID == list[j].ID){

          t_hh = list[j].hh - list[i].hh;
          t_mm = list[j].mm - list[i].mm;
          t_ss = list[j].ss - list[i].ss;

          if(t_hh < 1)
            t_hh *= -1;
          if(t_mm < 1)
            t_mm *= -1;
          if(t_ss < 1)
            t_ss *= -1;

          //printf("ID %d: %d:%d:%d\n", list[i].ID, t_hh, t_mm, t_ss);
          hh[k]=t_hh;
          mm[k]=t_mm;
          ss[k]=t_ss;

          total_time[k] = ((t_hh * 60 *60) + (t_mm * 60) + (t_ss));
          id[k] = list[i].ID;

          k++;
        }
      }

      count = k;
    }
//  }

  //printf("\n\n");

  if(strcmp(argv[1], "-r") == 0){
    int max = -100, min = 100000, index_of_max, index_of_min;

    for(int i=0; i<count; i++){
      if(total_time[i] > max){
        max = total_time[i];
        index_of_max = i;
      }

      if(total_time[i] < min){
        min = total_time[i];
        index_of_min = i;
      }
    }

    printf("Maximum time in the building: ID %d\n", list[index_of_max].ID);
    printf("Minimum time in the building: ID %d\n", list[index_of_min].ID);

  }

  if(strcmp(argv[1],"-v") == 0){
    for(int i=0; i<count; i++){
      printf("ID %d: %d:%d:%d\n", id[i], hh[i], mm[i], ss[i]);
    }
  }

}
