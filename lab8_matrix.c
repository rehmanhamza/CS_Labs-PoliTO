#include<stdio.h>
#include<stdbool.h>

#define N 5

int main(){
  int a[N][N]={{0, 0, 0, 4, 5,}, {1, 2, 0, 4, 5}, {1, 0, 0, 4, 0}, {1, 2, 3, 4, 5}, {1, 0, 0, 0, 0}};
  int flag=false, flag1=false;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
        if(((a[i][j] == 0) && (a[i][j+1] == 0) && (a[i][j+2] == 0))){
          flag=true;
          if(flag){
            printf("The sequence is found in the row %d.\n", i+1);
          }
        }
        if(((a[i][j] == 0) && (a[i+1][j] == 0) && (a[i+2][j] == 0))){
          flag1=true;
          if(flag1){
            printf("The sequence is found in the column %d.\n", j+1);
          }
        }
      }
    }

}
