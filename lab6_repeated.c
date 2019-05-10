#include<stdio.h>

#define N 10
void repeat(int v[], int size);

int main(){
  int v[N]={1,1,1,2,3,4,5,4,3,5}, size=N;
  repeat(v, size);

}

void repeat(int v[], int size){
  int flag[N]={0}, counter[N]={0};
  for(int i=0; i<size; i++){
    if(flag[i]==0){
      for(int j=i; j<size; j++){
        if(v[j]==v[i]){
          flag[j]=1;
          counter[i]++;
        }
      }
    }
  }

  for(int i=0; i<size; i++){
    if(counter[i] > 1){
      printf("%d occured this much %d times.\n", v[i], counter[i]);
    }
  }

}
