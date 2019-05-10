#include<stdio.h>
#include<string.h>
#include<ctype.h>
//#define MAX 15

int main(){
  char str1[]="importante";
  char str2[]="tan";

  int str1_length=strlen(str1);
  printf("String Length: %d\n\n", str1_length);

  for(int i=0; i<(strlen(str2)); i++){
    for(int j=i; j<(strlen(str1)); j++){
      if(str2[i] == str1[j]){
        printf("%c ", str1[j]);
      }
    }
  }
}
