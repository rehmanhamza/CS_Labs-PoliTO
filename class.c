#include<stdio.h>
#include<stdlib.h>

#define N 10

int main(){
  int a[N]={25,18,18,22,25,30,50,18,7,25}, val, found=0, count=0, place[N]={}, positive=0, j=0;
  printf("Enter a number to search in array: ");
  scanf("%d", &val);

  for(int i=0; i<N; i++){
    if(a[i] == val){
      found=1;
      count++;
      place[j]=i+1;
      j++;
    }
    if(a[i] >= 0){
      positive=1;
    }
  }

  if(found && positive){
    printf("\nAll the elements are +ve and element \"%d\" is in array and occured %d time(s) in array of size %d ", val, count, N);
    printf("and occured at the following position(s): \n");
    for(int i=0; i<N; i++){
      if(place[i]){
        printf("%d\t", place[i]);
      }
    }
  }
  else if(!found){
    printf("Not found.\n");
  }
  else{
    printf("Program exited with errors.\n");
  }
}
