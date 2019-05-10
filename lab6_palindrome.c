#include<stdio.h>

#define N 5

int main(){
  int a[N]={1,3,5,3,1}, flag=1;

  for(int i=0; i<N/2; i++){
    if(a[i]!=a[N-1-i]){
      flag=0;
    }
  }

  if(flag){
    printf("Palindrome.\n");
  }
  if(!flag){
    printf("Not a Palindrome.\n");
  }
}
