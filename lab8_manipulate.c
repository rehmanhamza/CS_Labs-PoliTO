#include<stdio.h>
#include<ctype.h>

#define N 10

int main(){
  char a[N];
  printf("Upto %d characters!.\n", N);
  gets(a);

  int i=0;
  while(a[i] != '\n'){
    if(islower(a[i])){
      a[i]=toupper(a[i]);
    }

    if(isdigit(a[i])){
      a[i]='*';
    }
    if(!isalpha(a[i])){
      a[i]='_';
    }

    i++;
  }

  puts(a);
}
