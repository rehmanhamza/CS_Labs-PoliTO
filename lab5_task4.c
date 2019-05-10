#include<stdio.h>

#define N 5

int main(){
  int a[N];
  printf("Enter %d numbers: \n", N);
  for(int i=0; i<N; i++){
    scanf("%d", &a[i]);
  }

  for(int i=0; i<N; i++){
    if(a[i] > a[i+1]){
        printf("Series is descending.\n");
        //break;
    }
    if(a[i] < a[i+1]){
      printf("Series is ascending.\n");
      //break;
    }
  }
}
