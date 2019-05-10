#include<stdio.h>

int main(){
  int a[10]={1,2,3,2,1,3,4,5,8,11}, b[10]={0};

  for(int i=0; i<10; i++){
    b[a[i]]++;
  }
  for(int i=0; i<10; i++){
    if(a[i] != 0)
      printf("%d = %d\n", a[i], i);
  }
}
