#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
#define MAX_LEN 40
int compare_dates(char *date1, char *date2);

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Wrong number of arguments.\n");
    return EXIT_FAILURE;
  }
  else{
    if(strcmp(argv[1], "file_dock.txt") != 0){
      printf("Invlaid file name.\n");
      return EXIT_FAILURE;
    }
    else{
      char str[MAX_LEN], good[MAX+1], date[MAX+1], info[MAX+1], max_date[MAX+1];
      int load;
      float loaded=0, amount=0;
      printf("Enter name: ");
      scanf("%s", info);
      FILE *file;

      file=fopen("file_dock.txt", "r");

      if(file==NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
      }
      else{
        while(fgets(str, MAX_LEN, file) != NULL){
          sscanf(str, "%s %s %d", good, date, &load);

          //printf("%s %s %d\n", good, date, load);

          if((strcmp(good, info) == 0) && load > 0){
            loaded++;
            amount += 10+(0.1*load);
            //printf("Load = %d\n", load);

            if(compare_dates(date, max_date) > 0){
              strcpy(max_date, date);
            }
          }
        }

        printf("Loaded = %0.2f\n", loaded);
        printf("Amount = %0.2f\n", amount);
        printf("Date = %s\n", max_date);
      }
    }
  }

  return EXIT_SUCCESS;
}


int compare_dates(char *date1, char *date2){
  int d1,m1,y1;
  int d2,m2,y2;
  char date1_ordered[MAX+1];
  char date2_ordered[MAX+1];

  sscanf(date1, "%d-%d-%d", &d1, &m1, &y1);
  sscanf(date2, "%d-%d-%d", &d2, &m2, &y2);

  sprintf(date1_ordered, "%d-%d-%d", y1, m1, d1);
  sprintf(date2_ordered, "%d-%d-%d", y2, m2, d2);

  return (strcmp(date1_ordered, date2_ordered));

}
