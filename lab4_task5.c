#include<stdio.h>

int main(){
  int a=0, b=1, c=0, n;
  printf("Enter limit:");
  scanf("%d", &n);
  printf("%d %d ", a, b);
  for(int i=0; i<n-2; i++){
    c=a+b;
    a=b;
    b=c;
    printf("%d ", c);
  }

  int aa=1, bb=2, cc=1, nn;
  printf("\n\nEnter limit (upto 9):");
  scanf("%d", &nn);
  printf("%d %d ", aa, bb);
  for(int i=0; i<nn-2; i++){
    cc=aa*bb;
    aa=bb;
    bb=cc;
    printf("%d ", cc);
  }
}
