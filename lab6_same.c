#include<stdio.h>

#define N 5

int sort(int v[], int size);

int main(){
  int v1[N]={15,4,12,13,29}, v2[N]={15,29,13,4,12}, flag=0, temp, size=N, count=0;
  //sorting arrays to make the program more efficient
  sort(v1, size);
  sort(v2, size);

  for(int i=0; i<N; i++){
    for(int j=i; j<N; j++){
      if(v1[i]==v2[j]){
        count++;
      }
    }
  }

  if(count==N){
    printf("Both arrays have same elements.\n");
  }
  else{
    printf("Both arrays does not have same elements.\n");
  }
}

int sort(int v[], int size){
  int temp;
  for(int i=0; i<size; i++){
    for(int j=i+1; j<size; j++){
      if(v[i] > v[j]){
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
      }
    }
  }

  return v;
}
