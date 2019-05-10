#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define N 3
#define M 15

int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product);
void print_all(char warehouse[][M], float price[], int n, float *avg, float *max);

int main(){
  char warehouse[N][M], new_product[M];
  float price[N], price_new_product;
  int check, n=N;

  for(int i=0; i<N; i++){
    price[i]=-2;
  }

  printf("\t\t***Possible Operations***\n\n");
  printf("1. Insertion of a new product and the associated price.\n"
         "2. Print the current list (a table with product names and prices).\n"
         "3. Exit the program.\n\n");

  do{
    printf("Enter the index number: ");
    scanf("%d", &check);

    if(check==1){
      printf("Product name: ");
      scanf("%s", new_product);
      printf("Price: ");
      scanf("%f", &price_new_product);
      insert_product(warehouse, price, n, new_product, price_new_product);
    }
    if(check==2){
      int i=0, sum=0;
      float avg, max=price[0];
      while(price[i] != -2){
        sum += price[i];
        if(max<price[i]){
          max=price[i];
        }
        i++;
      }
      avg=(float)sum/i;

      print_all(warehouse, price, n, &avg, &max);
    }
  }while(check != 3);
}

int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product){
  int returnValue, flag1=false, flag2=false;
  for(int i=0; i<n && flag1==false; i++){
    if(price[i] != -2 && strcmp(warehouse[i], new_product)==0){
      flag1=true;
    }
    if(flag1==false){
      for(int i=0; i<n && flag2==false; i++){
        if(price[i]==-2){
          flag2=true;
        }
        if(flag2==true){
          strcpy(warehouse[i-1],new_product);
          price[i-1]=price_new_product;

          returnValue=1;
        }
        else{
          returnValue=2;
        }
      }
    }
    else{
      returnValue=0;
    }
  }

  return returnValue;

}

void print_all(char warehouse[][M], float price[], int n, float *avg, float *max){
  int i=0;
  while(price[i] != -2){
    printf("Product: %s\tPrice: %0.2f\n\n", warehouse[i], price[i]);

    i++;
  }

  printf("Average = %0.2f\n", *avg);
  printf("Maximum = %0.2f\n", *max);
}
