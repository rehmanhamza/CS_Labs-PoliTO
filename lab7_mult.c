#include<stdlib.h>

#define N 5
void mult(int a[], int x, int size);

int main(){
  int a[N]={1,2,3,4,5}, x=2, size=N;
  mult(a, x, size);

  for(int i=0; i<N; i++){
    printf("%d\n", a[i]);
  }
}

void mult(int a[], int x, int size){
  for(int i=0; i<size; i++){
    a[i] *= x;
  }
}
