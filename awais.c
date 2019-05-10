#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void f();
//int* f();

/*void transform(int x){
  switch (x) {
    case 1: x+=1;
    break;
    case 2: x-=2;
    break;
    case 3: x*=3;
    break;
    default: x=x*x;
  }

  printf("%d\n", x);
}*/
int main(){
    //for(;;)
        
    /*double x = 3.1;
    float y = 3.1;
    if(x == y){
        printf("Yes\n");
    }
    else{
        printf("Not Equal\n");
    }*/
  /*int x=1;
  while(x<=5){
    if(x%2==0||x%3==0){
      printf(" OK");
    }
    else{
      printf(" NO");
    }
    x++;
  }*/
  /*int x=-1;
  transform(x);
  return 1;*/
  /*char str[]="Genoa";
  for(int i=0;i<6;i++){
    if(str[i]>='a'&&str[i]<='z'){
      str[i]=str[i]+'A'-'a';
    }
  }

  puts(str);*/
  //f();
  /*int x=1;
  for(int i=0;i<10;i++){
    x=x+x;
    if(x>=5){
      //printf("%d\n", );
      break;
    }
  }

  printf("%d\n", x);*/
  /*char c='a';
  int x=c;
  printf("%d\n", x);

  double a=3;
  double b=0.3;
  int h=a*b;
  printf("%d\n", h);*/
}

/*void f() {
    struct {
        char s1[3];
        char s2[5];
    } s;

    strcpy(s.s1, "ok");
    strcpy(s.s2, "flag");

    printf("%s\n", (&((char*)&s)[3]));
}*/

/*int* f(int x) {
    unsigned char i = (unsigned char)x;
    int* v = (int*)malloc(100*sizeof(int));
    if (v != NULL && (char)i < 100) v[i] = x;
    return v;
}*/
