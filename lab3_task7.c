#include<stdio.h>
#include<stdlib.h>

int main(){
  int a, b, c, d;
  printf("Enter 4 numbers:\n");
  scanf("%d\n%d\n%d\n%d", &a, &b, &c, &d);
  if(a <= 0 && a > 1000){
    a=0;
    printf("Value can't be in this range %d.\n", a);
  }
  if(b <= 0 && b > 1000){
    b=0;
    printf("Value can't be in this range %d.\n", b);
  }
  if(c <= 0 && c > 1000){
    c=0;
    printf("Value can't be in this range %d.\n", c);
  }
  if(d <= 0 && d > 1000){
    d=0;
    printf("Value can't be in this range %d.\n", d);
  }

  int max1, max2, max3, max4, max5;
  max1=a-b;
  max2=a-c;
  max3=a-d;
  max4=b-c;
  max5=b-d;
  if(max1 < 0){
    max1 *= -1;
  }
  if(max2 < 0){
    max2 *= -1;
  }
  if(max3 < 0){
    max3 *= -1;
  }
  if(max4 < 0){
    max4 *= -1;
  }
  if(max5 < 0){
    max5 *= -1;
  }

  if(max1 > max2 && max1 > max3 && max1 > max4 && max1 > max5){
    printf("The maximum difference is %d\n", max1);
  }
  if(max2 > max1 && max2 > max3 && max2 > max4 && max2 > max5){
    printf("The maximum difference is %d\n", max2);
  }
  if(max3 > max1 && max3 > max2 && max3 > max4 && max3 > max5){
    printf("The maximum difference is %d\n", max3);
  }
  if(max4 > max1 && max4 > max2 && max4 > max3 && max4 > max5){
    printf("The maximum difference is %d\n", max4);
  }
  if(max5 > max1 && max5 > max2 && max5 > max3 && max5 > max4){
    printf("The maximum difference is %d\n", max5);
  }

}
