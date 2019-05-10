#include<stdio.h>

int power(int b, int e);

int main(){
  int e, b, result;
  printf("Enter Base: ");
  scanf("%d", &b);
  printf("Enter Exponent: ");
  scanf("%d", &e);
  result=power(b, e);
  printf("Result = %d", result);

}

int power(int b, int e){
  int n=1;

  for(int i=0; i<e; i++){
    n *= b;
  }

  return n;
}
