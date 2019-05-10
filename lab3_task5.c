#include<stdio.h>

int main(){
  int a, b, c, sum1, sum2 ,sum3;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  sum1=a+b;
  sum2=a+c;
  sum3=b+c;

  if(a < sum3 && b < sum2 && c < sum1){
    printf("Valid Triangle.\n");
    if(a == b == c){
      printf("Equilateral.\n");
    }
    if(a == b  && b != c && a != c){
      printf("Isosceles.\n");
    }
    if( a !=b && b != c && a != c){
      printf("Scalene.\n");
    }
  }
  if(a == sum1 || b == sum2 || c == sum3){
    printf("Degenerate Triangle.\n");
  }
}
