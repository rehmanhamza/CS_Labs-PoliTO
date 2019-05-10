#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 15
#define M 100
#define R 200

typedef struct{
  char product[N+1];
  int quantity;
} WAREHOUSE;

typedef struct{
  char request[N+1];
} REQUEST;

int main(){
  WAREHOUSE temp, list[N];
  REQUEST temp1, r_list[N+1];

  strcpy(temp.product, "NA");
  strcpy(temp1.request,"NA");
  temp.quantity = -1;

  FILE *file1, *file2;

  file1=fopen("file_warehouse.txt", "r");

  if(file1==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  int i=0, limit_w=0;

  while(!feof(file1)){
    fscanf(file1, "%s %d", list[i].product, &list[i].quantity);

    i++;
  }

  limit_w = i;

  fclose(file1);

  file2=fopen("file_request.txt", "r");

  if(file2==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  int j=0, limit_r=0;

  while(!feof(file2)){
    fscanf(file2, "%s", r_list[j].request);

    j++;
  }

  limit_r = j;

  fclose(file2);

  for(int i=0; i<limit_w; i++){
    for(int j=0; j<limit_r; j++){
      if(strcmp(list[i].product, r_list[j].request) == 0){
        list[i].quantity--;
        //printf("The following products are not in the warehouse stock: %s\n", r_list[j].request);
      }
    }
  }

  for(int i=0; i<limit_w; i++){
    for(int j=i; j<limit_r-1; j++){
      if(strcmp(r_list[j].request, list[i].product) != 0){
        printf("The following products are not in the warehouse stock: %s\n", r_list[j].request);
      }
    }
  }

  for(int i=0; i<limit_w; i++){
    if(list[i].quantity < 0){
      printf("The excess quantity of %s required is: %d\n", list[i].product, list[i].quantity * -1);
    }
  }

  for(int i=0; i<limit_w; i++){
    if(list[i].quantity < 0){
      list[i].quantity = 0;
    }
  }

  printf("\n\n");

  int *update_quantity;

  update_quantity = (int *) malloc(sizeof(int)*limit_w);

  for(int i=0; i<limit_w; i++){
    update_quantity[i] = list[i].quantity;
  }

  for(int i=0; i<limit_w-1; i++){
    printf("%s %d\n", list[i].product, update_quantity[i]);
  }

  /*file1=fopen("file_warehouse.txt", "w");

  if(file1 == NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  for(int i=0; i<limit_w-1; i++){
    fprintf(file1, "%s %d\n", list[i].product, list[i].quantity);
  }

  fcose(file1);*/

  return EXIT_SUCCESS;
}
