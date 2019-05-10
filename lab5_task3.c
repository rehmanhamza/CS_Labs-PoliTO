#include<stdio.h>

#define N 5

int main(){
  int v1[N]={}, v2[N]={}, v, count1=0, count2=0;
  for(int i=0; i<N; i++){
    scanf("%d", &v);
    if(v > 0 || (v < 0 && v%3 == 0)){
      v1[i]=v;
      count1++;
      if(count1 == N){
        printf("Array v1 size if full.\n");
        break;
      }
    }

    else if(v < 0 && (v%3 != 0 || v%2 == 0)){
      v2[i]=v;
      count2++;
      if(count2 == N){
        printf("Array v2 size if full.\n");
        break;
      }
    }
    else{
      printf("Wrong Input!\n");
    }

  }
  
  printf("v1:\n");
  for(int i=0; i<N; i++){
    printf("%d\t", v1[i]);
  }

  printf("\nv2:\n");
  for(int i=0; i<N; i++){
    printf("%d\t", v2[i]);
  }
}
