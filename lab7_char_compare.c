#include<stdio.h>
#include<ctype.h>

#define N 2

int main(){
  char a[N], i=0;
  printf("Enter two characters: ");
  gets(a);

  while(a[i] != '\0'){
    if(isalpha(a[i]) && isalpha(a[i+1])){
      if(a[i] == a[i+1]){
        printf("Equal.\n");
      }
      if(a[i] > a[i+1]){
        printf("Original Form: %c %c\n\n", a[i], a[i+1]);
        printf("Alphabatic Order: %c %c\n", a[i+1], a[i]);
      }
      if(a[i] < a[i+1]){
      printf("%c %c\n", a[i], a[i+1]);
    }
  }
  if(isdigit(a[i]) || isdigit(a[i+1])){
    printf("Atleast one of the character is integer.\n");
  }
    i++;
  }
}
