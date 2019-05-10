#include<stdio.h>
#include<math.h>

#define N 5
int *power(int base[], int power[]);

int main(){
  int base[N]={5,2,7,4,9}, exponent[N]={2,6,1,8,3};
  int *p=power(base, exponent);

  for(int i=0; i<N; i++){
    printf("%d\n", *(p+i));
  }

}

int *power(int base[], int power[]){
  int result[N];

  for(int i=0; i<N; i++){
    result[i]=pow(base[i], power[i]);
  }

  return result;
}
