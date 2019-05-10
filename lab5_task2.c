#include<stdio.h>

#define N 10

int main(){
  int a[N];
  printf("Enter %d Elements: \n", N);
  for(int i=0; i<N; i++){
    scanf("%d", &a[i]);
  }

  int sum=0;
  float average;
  for(int i=0; i<N; i++){
    sum += a[i];
  }

  average=sum/N;
  printf("Average: %f\n", average);

  int max=a[0], postion;
  for(int i=0; i<N; i++){
    if(a[i] >  max){
      max=a[i];
      postion=i;
    }
  }

  printf("Maximum number in array is %d at postion %d.\n", max, postion+1);
}
