#include<stdio.h>

#define N 10

int main(){
  int v[N]={25,18,1,22,5,30,50,8,7,2}, duplicate=0;  //using flags make a program a lot easier to make.

  for(int j=0; j<N; j++){
    for(int i=j+1; i<N; i++){
      if(v[j]==v[i]){
        duplicate=1;
      }
    }
  }

  if(duplicate){
    printf("Duplicate Found!\n");
  }

  if(!duplicate){
    printf("No duplicate found.\n");
  }
}
