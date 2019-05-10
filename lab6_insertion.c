#include<stdio.h>

#define N 5

int main(){
  int v[N], n, position;
  for(int i=0; i<N; i++){
    scanf("%d", &n);

    position=i;

    for(int j=0; j<i; j++){
      if(v[j] > n){
        position=j;
        j=i;
        //break;
      }
    }

    for(int j=i; j>position; j--){
      v[j]=v[j-1];
    }

    v[position]=n;

    printf("We are at %d position of array: ", i+1);
    for(int j=0; j<i+1; j++){
      printf("%d ", v[j]);
    }
    printf("\n");
  }
}
