#include<stdio.h>
#include<stdlib.h>

int main(){
  int a, b;
  float x;
  printf("Enter coefficient of a: ");
  scanf("%d", &a);

  printf("Enter coefficient of b: ");
  scanf("%d", &b);

  b *= -1;

  if(a==0){
    printf("Can't determine value of x!\n");
  }
  
  x=b/a;
  printf("x = %f\n", x);
}
