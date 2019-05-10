#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(int argc, char *argv[]){
  int sum=0;
  printf("Number of arguments = %d\n\n", argc);

  if(argc-1 < 2 || argc-1 > 2){
    printf("Invalid number of arguments.\n");
  }
  else{
    for(int i=1; i<argc; i++){
      if(atoi(argv[i]) < -10000 || atoi(argv[i]) > 10000){
        printf("Numbers out of bound.\n");
        return EXIT_FAILURE;
      }
      else{
      sum += atoi(argv[i]);
      }
    }

    printf("Addition = %d\n", sum);
  }

  getch();

  return EXIT_SUCCESS;
}
