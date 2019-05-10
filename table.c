#include<stdio.h>

void table(int n);

int main(){
  int a=2;
  table(a);
  /*for(int i=1; i<=10; i++){
    printf("%d x %d = %d\n", a, i, a*i);
  }*/
}

void table(int n){
  for(int i=1; i<=10; i++){
    printf("%d x %d = %d\n", n, i, n*i);
  }
}
