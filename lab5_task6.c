#include<stdio.h>

#define N 5

int main(){
  int v[N];
  for(int i=0; i<N; i++){
    scanf("%d", &v[i]);
  }

  int flag1, flag2, count;
  for(int i=0; i<N; i++){
    flag1=0;
    flag2=0;
    count=1;
    for(int j=i+1; j<N; j++){
      if(v[i]==v[j]){
        flag1=1;
        count++;
      }
    }

    for(int k=i-1; k>=0; k--){
      if(v[k]==v[i]){
        flag2=1;
      }
    }

    if(flag1==0 && flag2==0){
        printf("\nNumber %d is not repeated\n", v[i]);
      }

    else if(flag2==0){
        printf("\nNumber %d is repeated\n", v[i]);
        printf("Number of occurences = %d\n", count);
    }
  }
}
