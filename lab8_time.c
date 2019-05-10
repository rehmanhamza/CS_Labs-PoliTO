#include<stdio.h>

#define MAX 5

int main(){
  char time1[MAX+1], time2[MAX+1], str[MAX+MAX+1];
  int h1, h2, m1, m2, t1, t2, distance;
  printf("Enter 1st time: ");
  gets(time1);
  printf("Enter 2nd time: ");
  gets(time2);

  if((!sscanf(time1, "%d:%d", &h1, &m1)) || h1<0 || h1>23 || m1<0 || m1>59){
    printf("Invalid 1st time.\n");
  }
  if((!sscanf(time2, "%d:%d", &h2, &m2)) || h2<0 || h2>23 || m2<0 || m2>59){
    printf("Invalid 2nd time.\n");
    return -1;
  }

  t1=(h1*60+m1);
  t2=(h2*60+m2);
  distance=t2-t1;

  printf("\n\n");

  if(t1 < t2){
    printf("1st time is less than 2nd time.\n");
    sprintf(str, "Calculated interval in minutes = %d\n", distance);
    puts(str);
  }
  else if(t2 < t1){
    printf("2nd time is less than 1st time.\n");
    sprintf(str, "Calculated interval in minutes = %d\n", distance);
    puts(str);
  }
  else{
    printf("1st time is equal to 2nd time.\n");
  }
}
