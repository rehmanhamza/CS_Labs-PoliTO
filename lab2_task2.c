#include<stdio.h>
#include<stdlib.h>

int main(){
  int var1=25, var2=-53;
  /*tmp=var1;
  var1=var2;
  var2=tmp;*/

  var1=var1+var2;
  var2=var1-var2;
  var1=var1-var2;
  printf("var1 = %d\nvar2 = %d\n", var1, var2);
}
