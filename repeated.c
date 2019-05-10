#include<stdio.h>

#define N 10

int main(){
  int a[N]={1,1,1,2,3,4,5,4,3,5}, flag[N]={0}, counter[N]={0};

  for(int i=0; i<N; i++){
    if(flag[i]==0){
      for(int j=i; j<N; j++){
        if(a[j]==a[i]){
          flag[j]=1;
          counter[i]++;
        }
      }
    }
  }

  for(int i=0; i<N; i++){
    if(counter[i] > 1)
      printf("%d occured this much %d times\n", a[i], counter[i]);
  }
}
