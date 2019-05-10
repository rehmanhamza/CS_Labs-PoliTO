#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50
#define MAX_LEN 20
int compare_dates(char *date1, char *date2);

int main(int argc, char *argv[]){

  if(argc != 2){
    printf("Wrong number of arguments.\n");
    return EXIT_FAILURE;
  }

  int distance, r;
  char str[MAX+1], city[MAX_LEN+1], date[(MAX_LEN/2)+1], type;
  char max_date[(MAX_LEN/2)+1]={"00/00/0000"};
  float total_distance=0, cost=0;

  FILE *file;

  file=fopen("file_travels.dat", "r");

  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    int i=0;
    while(fgets(str, MAX, file) != NULL){
      r=sscanf(str, "%s %s %d %c", city, date, &distance, &type);
      i++;
      if(r!=4){
        printf("Error reading from line %d\n", i);
      }

      if(strcmp(city, argv[1])==0 && type=='F'){
        total_distance += (distance/1000);
        cost += 5+(0.1*(distance/1000));

        if(compare_dates(date, max_date) > 0){
          strcpy(max_date, date);
        }
      }

    }
  }

  printf("distance = %0.2f\n", total_distance);
  printf("cost = %0.2f\n", cost);
  printf("date = %s\n", max_date);

  return EXIT_SUCCESS;

}

int compare_dates(char *date1, char *date2){
  int d1, m1, y1;
  int d2, m2, y2;
  char date1_ordered[(MAX_LEN/2)+1];
  char date2_ordered[(MAX_LEN/2)+1];

  sscanf(date1, "%d/%d/%d", &d1, &m1, &y1);
  sscanf(date2, "%d/%d/%d", &d2, &m2, &y2);
  sprintf(date1_ordered, "%d/%d/%d", y1, m1, d1);
  sprintf(date2_ordered, "%d/%d/%d", y2, m2, d2);

  return(strcmp(date1_ordered, date2_ordered));
}
