#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
#define MAX_LEN 50

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("Wrong number of arguments.\n");
    return EXIT_FAILURE;
  }
  else{
    char str[MAX_LEN+1], dstation[MAX+1], dtime[(MAX/2)], astation[MAX+1], atime[(MAX/2)];
    int arrive=0, depart=0;
    FILE *file;

    file=fopen(argv[1],"r");

    if(file == NULL){
      perror("Error opening file");
      return EXIT_FAILURE;
    }
    else{
      while(fgets(str, MAX_LEN, file) != NULL){
        sscanf(str, "%s %s %s %s", dstation, dtime, astation, atime);

        if(strcmp(dstation, argv[2]) == 0){
          depart++;
          printf("%s %s %s %s\n", dstation, dtime, astation, atime);
        }
        if(strcmp(astation, argv[2]) == 0){
          arrive++;
          printf("%s %s %s %s\n", dstation, dtime, astation, atime);
        }
      }
      printf("No. of Trains arriving at %s: %d\n", argv[2], arrive);
      printf("No.of Trains departing from %s: %d\n", argv[2], depart);

      fclose(file);
    }
  }
}
