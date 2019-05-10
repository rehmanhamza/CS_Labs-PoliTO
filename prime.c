#include<stdio.h>

int main(){
  int num=5, flag=0;

  for(int i=2; i<num/2; i++){
    if(num % i == 0){
      flag=1;
      break;
    }
  }
    if(flag == 0){
        printf("Prime: %d\n",num);
      }
      else{
        printf("Not prime.\n");
      }


}
