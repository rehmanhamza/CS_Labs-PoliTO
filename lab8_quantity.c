#include<stdio.h>
#include<string.h>

#define MAX 30

int main(){
  char str1[MAX+1], str2[MAX+1], str3[MAX+1], str[MAX+1], product1[MAX/2], product2[MAX/2], product3[MAX/2], product[MAX/2];
  int price1, price2, price3, quantity, total_price;
  printf("Enter 1st product and it's price: ");
  gets(str1);
  printf("Enter 2nd product and it's price: ");
  gets(str2);
  printf("Enter 3rd product and it's price: ");
  gets(str3);

  sscanf(str1, "%s %d", &product1, &price1);
  sscanf(str2, "%s %d", &product2, &price2);
  sscanf(str3, "%s %d", &product3, &price3);

  printf("\n\t\t***List***\n\n");
  printf("Product Name: %s\tPrice: %d\n", product1, price1);
  printf("Product Name: %s\tPrice: %d\n", product2, price2);
  printf("Product Name: %s\tPrice: %d\n", product3, price3);

  x:
  printf("\n\nEnter a product from list and required quantity: ");
  gets(str);

  sscanf(str, "%s %d", &product, &quantity);

  if((strcmp(product, product1) == 0)){
    printf("Product found in the list.\n");
    total_price = quantity*price1;
    printf("\n\nTotal Price: %d\n", total_price);
  }

  if((strcmp(product, product2) == 0)){
    printf("Product found in the list.\n");
    total_price = quantity*price2;
    printf("\n\nTotal Price: %d\n", total_price);
  }

  if((strcmp(product, product3) == 0)){
    printf("Product found in the list.\n");
    total_price = quantity*price3;
    printf("\n\nTotal Price: %d\n", total_price);
  }

  if(!(strcmp(product, product1) == 0) && !(strcmp(product, product2) == 0) && !(strcmp(product, product3) == 0)){
    printf("Product not in the list.\n");
    goto x;
  }

}
