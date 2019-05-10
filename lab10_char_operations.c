#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  printf("Number of arguments = %d\n", argc-1);
  if(argc-1 < 3 || argc-1 > 3){
    printf("Invlaid number of arguments.\n");
  }
  else{
    int x, y;
    char ch;
    x=atoi(argv[1]);
    y=atoi(argv[2]);
    sscanf(argv[3], "%c", &ch);

    if(ch == 'a'){
      printf("Sum = %d\n", x+y);
    }
    else if(ch == 'b'){
      printf("Subtraction = %d\n", x-y);
    }
    else if(ch == 'c'){
      printf("Product = %d\n", x*y);
    }
    else if(ch == 'd'){
      if(y == 0){
        printf("Can't divide by zero.\n");
        return EXIT_FAILURE;
      }
      else{
        printf("Division = %f\n", ((float)x/y));
      }
    }
    else{
      printf("Invalid Operarion!.\n");
      return EXIT_FAILURE;
    }
  }

}
