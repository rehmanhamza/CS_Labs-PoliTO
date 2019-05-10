#include<stdio.h>

int main(){
  int a, b, rem;
  printf("Enter num1: ");
  scanf("%d", &a);
  printf("Enter num2: ");
  scanf("%d", &b);

  while(a != b){
    if(a > b){
      a -= b;
    }
    else{
      b -= a;
    }
  }
  printf("GCD = %d\n", a);
}
