#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(int argc, char *argv[]){
  printf("You entered %d arguments.\n", argc-1);
  if(argc-1 < 3){
    printf("Arguments less than 3.\n");
    return EXIT_FAILURE;
  }
  else{
    printf("The arguments are:\n");
    for(int i=1; i<argc; i++){
      printf("%s\n", argv[i]);
    }
    int product=1;
    for(int i=1; i<argc; i++){
      product *= atoi(argv[i]);
    }

    printf("Product = %d\n", product);
  }

  printf("\n\nEnter any key to continue...");
  getch();
}
