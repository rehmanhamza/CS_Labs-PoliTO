#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int a, b, c, d;
  printf("\tCaculating roots of a quadratic equation\n");
  printf("Enter coefficients: \n");
  scanf("%d\n%d\n%d", &a, &b,&c);

    d=(pow(b,2)-4*a*c);

    if(d > 0){
      printf("The equation has two REAL distinct roots.\n");
    }
    else if(d < 0){
      printf("The equation has NO REAL roots.\n");
    }
    else{
      printf("The equation has two REAL coincident roots.\n");
    }
}
