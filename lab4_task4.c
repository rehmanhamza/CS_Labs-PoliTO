#include<stdio.h>

int main(){
  int n;
  printf("Enter number of rows: ");
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      printf("* ");
    }
    printf("\n");
  }

  printf("\n\n\tFloyd's Triangle\n");
  int rows, num=1;
  printf("Enter number of rows:");
  scanf("%d", &rows);
  for(int i=0; i<rows; i++){
    for(int j=0; j<=i; j++){
      printf("%d ", num);
      ++num;
    }
    printf("\n");
  }
}
