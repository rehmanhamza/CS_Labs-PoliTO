#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3
#define M 15

int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product);
int update_product(char warehouse[][M], float price[], int n, char product[], float new_price);
int remove_product(char warehouse[][M], float price[], int n, char old_product[]);
void print_all(char warehouse[][M], float price[], int n, float *avg, float *max);

int main(){
  char warehouse[N][M], new_product[M], product[M], old_product[M];
  float price[N], price_new_product, new_price;
  int check, n=N;

  for(int i=0; i<N; i++){
    price[i]=-2;
  }

  printf("\t\t***Possible Operations***\n\n");
  printf("1. Insertion of a new product and the associated price.\n"
         "2. Print the current list (a table with product names and prices).\n"
         "3. Update price of existing product.\n"
         "4. Remove existing product.\n"
         "5. Exit the program.\n\n");

  do{
    printf("Enter the index number: ");
    scanf("%d", &check);

    if(check==1){
      int result;
      printf("Product name: ");
      scanf("%s", new_product);
      printf("Price: ");
      scanf("%f", &price_new_product);
      //insert_product(warehouse, price, n, new_product, price_new_product);

      result=insert_product(warehouse, price, n, new_product, price_new_product);
      if(result==1){
        printf("Product and price inserted successfully.\n");
      }
      else{
        if(result==2){
          printf("PRODUCT ALREADY IN THE LIST!\n");
        }
        else if(result==0){
          printf("PRODUCT INSERTION FAILED!\n");
        }
      }
    }
    if(check==2){
      float avg;
      float max;
      print_all(warehouse, price, n, &avg, &max);
      printf("Average price is %f, the highest price is %f.\n", avg, max);
    }
    if(check==3){
      int result;
      printf("Product name: ");
      scanf("%s", product);
      printf("Updated Price: ");
      scanf("%f", &new_price);

      result=update_product(warehouse, price, n, product, new_price);
      printf("Result = %d\n", result);
    }
    if(check==4){
      int result;
      printf("Enter product to be removed: ");
      scanf("%s", old_product);

      result=remove_product(warehouse, price, n, old_product);
      printf("Result = %d\n", result);
    }
  }while(check != 5);
}

int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product){
  int slot=-1, flag=0;

  for(int i=0; i<n && (!flag); i++){
    if(!flag && price[i] != -2 && strcmp(warehouse[i], new_product) == 0){
      flag=1;
    }

    if(slot == -1 && price[i] == -2){
      slot=i;
    }
  }
    if(flag){
      return 0;
    }
    if(slot == -1){
      return 2;
    }
    else{
      strcpy(warehouse[slot], new_product);
      price[slot]=price_new_product;
      return 1;
    }

}

int update_product(char warehouse[][M], float price[], int n, char product[], float new_price){
  int returnValue;
  for(int i=0; i<n; i++){
    if(strcmp(warehouse[i], product)==0){
      price[i]=new_price;
      returnValue=1;
    }
    else{
      returnValue=0;
    }
  }

  return returnValue;

}

int remove_product(char warehouse[][M], float price[], int n, char old_product[]){
  int returnValue;
  for(int i=0; i<n; i++){
    if(strcmp(warehouse[i], old_product)==0){
      price[i]=-2;
      printf("Product Found.\n");
      returnValue=1;
    }
  }

  return returnValue;
}

void print_all(char warehouse[][M], float price[], int n, float *avg, float *max){
  int products=0;
  float total_price=0, max_price=-2;

  for (int i=0; i<n ; i++){
      if (price[i] != -2){
          if (max_price < price[i]){
              max_price = price[i];
            }
          products++;
          total_price += price[i];

          printf("%s %0.2f\n", warehouse[i], price[i]);
      }
  }

  if (products != 0)
      *avg = total_price / products;
  else
      *avg = -2;

  *max = max_price;
}
