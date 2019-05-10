#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
  char a[3][10];
  char b[10];

  printf("Enter 3 words to sort them:\n");
  for(int i=0; i<3; i++){
    gets(a[i]);
  }

  for(int i=0; i<2; i++){
    for(int j=i+1; j<3; j++){
      if(strcmp(a[i], a[j]) > 0){
        strcpy(b, a[i]);
        strcpy(a[i], a[j]);
        strcpy(a[j], b);
      }
    }
  }

  printf("After sorting:\n");
  for(int i=0; i<3; i++){
    puts(a[i]);
  }
}
