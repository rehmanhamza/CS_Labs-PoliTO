#include<stdio.h>
#include<malloc.h>

int main(){
  int n, *arr, sum=0;
  float avg;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("Enter a sequence of numbers:\n");
  arr=(int*) malloc(n * sizeof(int));

  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(int i=0; i<n; i++){
    sum += arr[i];
  }
  avg=sum/n;
  if(avg > n){
    printf("%f\n", avg);
  }
  else{
    printf("N is greater than average!\n");
  }

  free(arr);
}
