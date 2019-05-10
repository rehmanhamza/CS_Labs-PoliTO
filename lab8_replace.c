#include<stdio.h>
#include<stdlib.h>

int main(){
    char prevChar = '\0';
    char currChar = '_';

    printf("currChar = %c\n", currChar);
    printf("prevChar = %c\n", prevChar);

    do {
        currChar = getchar();
        if (currChar != -1){
            if (currChar == prevChar) {
                prevChar = '\0';
            } else if (prevChar != 'c' && currChar != 'c') {
                putchar(currChar);
            } else if (prevChar == 'c' && currChar == 'h') {
                putchar('k');
            } else if (prevChar == 'c' && currChar != 'h') {
                putchar(prevChar);
                putchar(currChar);
            }

            prevChar = currChar;
        }
    } while (currChar != -1);

    return EXIT_SUCCESS;
  }
