#include <stdio.h>

#define MAXCAR 128
char *deleted(char str1[], char str2[]);

int main(){
  char str1[MAXCAR], str2[MAXCAR];
  printf("Enter str1: ");
  scanf("%s", str1);
  printf("Enter str2: ");
  scanf("%s", str2);

  printf("\n\nstr1-str2: %s\n\n", deleted(str1, str2));
}

char *deleted(char str1[], char str2[]){
  int i, j, k;

  for(i=j=0; str1[i] != '\0'; i++){
    for(k=0; str2[k] && str1[i] != str2[k]; k++);
    printf("i = %d\nk = %d\n", i, k);
      if(str2[k] == '\0'){
        str1[j++]=str1[i];
        printf("\n\nIn if()\nj = %d\n", j);
      }
  }
  str1[j]='\0';
  printf("\n\nOutside if()\nj = %d\n", j);

  return str1;
}
