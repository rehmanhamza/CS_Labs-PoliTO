#include<stdio.h>

#define N 10

int main(){
  int a[N];
  for(int i=0; i<N; i++){
    scanf("%d", &a[i]);
  }

  //int count=0, postion;

  for(int i=0; i<N; i++){
    if(a[i] < a[i+1] && a[i+1] < a[i+2]){
      printf("Found: i = %d, %d %d %d\n", i, a[i], a[i+1], a[i+2]);
      /*count++;
      if(count == 3){
        postion=i-1;
        printf("There is a growing sequence among three numbers which starts from postion %d.\n", postion+1);
      }*/
    }
  }
}
