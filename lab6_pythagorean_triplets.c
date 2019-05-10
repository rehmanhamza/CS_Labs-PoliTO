#include<stdio.h>
#include<stdbool.h>

bool verify_triplets(int a, int b, int c);

int main(){
  int a, b, c=0, m=2, limit;
  printf("\t\tPythagorean Triplets\n");
  printf("Enter Limit: ");
  scanf("%d", &limit);

  while(c < limit){
    for(int i=1; i<m; i++){
      a=m*m-i*i;
      b=2*m*i;
      c=m*m+i*i;

      if(c > limit){
        break;
      }
      printf("a = %d\tb = %d\tc = %d\n",a, b, c);
      printf("Return Value: %d.\n", verify_triplets(a,b,c));
    }
    m++;
  }
}

bool verify_triplets(int a, int b, int c){
  if(((a*a) + (b*b) == (c*c))){
    return true;
  }
  else{
    return false;
  }
}
