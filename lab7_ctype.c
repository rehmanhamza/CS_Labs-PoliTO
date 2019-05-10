#include<stdio.h>
#include<ctype.h>

int main(){
  char a[]="hello 123 world !";
  int alphaCount=0, spaceCount=0, upperCount=0, digitCount=0, wordCount=0, i=0;

  while(a[i] != '\0'){
    if(isalpha(a[i])){
      alphaCount++;
    }
    if(isspace(a[i])){
      spaceCount++;
    }
    if(isupper(a[i])){
      upperCount++;
    }
    if(isdigit(a[i])){
      digitCount++;
    }
    if(i==0){
      if(isalpha(a[i])){
        wordCount++;
      }
    }
    if(isspace(a[i]) && isalpha(a[i+1])){
      wordCount++;
    }

    i++;
  }

  printf("alphaCount = %d\nspaceCount = %d\nupperCount = %d\ndigitCount = %d\nwordCount = %d\n",alphaCount, spaceCount, upperCount, digitCount, wordCount);

}
