#include<stdio.h>
#include<ctype.h>

int main(){
  char a[]="fatti non foste\nper viver come bruti\nma per seguir virtute e canoscenza";
  int i=0, count=0, lines=0;
  float avgWordLength;
  while(a[i] != '\0'){
    if(i==0){
      a[i]=toupper(a[i]);
      if(isalpha(a[i])){
        count++;
        lines++;
      }
    }
    if(isspace(a[i])){
      a[i+1]=toupper(a[i+1]);
      count++;
    }
    if(a[i]=='\n'){
      lines++;
    }

    i++;
  }

  avgWordLength=(i/count);

  printf("%s\n\nWords_Count = %d\n\nNumber_of_Letters = %d\n\nNumber_of_lines = %d\n\nAverage Word Length = %f\n", a, count, i, lines, avgWordLength);
}
