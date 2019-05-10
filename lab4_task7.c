#include<stdio.h>
#include<malloc.h>
#include<limits.h>

int factorial(int n);

int main(){
  printf("Range of \"int\" from %d to %d \n", INT_MIN, INT_MAX);
  printf("Range of \"char\" from %d to %d \n", CHAR_MIN, CHAR_MAX);
  //printf("Range of \"float\" from %d to %d \n", FLT_MIN, FLT_MAX);

  int *a;
  int n;
  scanf("%d", &n);
  a=(int *) malloc (n * sizeof(int));
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(int i=0; i<n; i++){
    a[i]=factorial(a[i]);
  }

  for(int i=0; i<n; i++){
    printf("%d\n", a[i] );
  }

}

int factorial (int n){
  if(n==0){
    return 1;
  }
  else{
    return(n*factorial(n-1));
  }
}
