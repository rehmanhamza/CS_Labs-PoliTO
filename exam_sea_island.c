#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 10
#define COLUMNS 40
int main(){
  char map[ROWS][COLUMNS+1];
  int x, y, terminate=false, countX, countY;

  FILE *file;
  file=fopen("file_map.dat", "r");

  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  else{
    for(int i=0; i<ROWS; i++){
      //for(int j=0; j<COLUMNS; j++){
      fscanf(file, "%s", map[i]);//  map[i][j]=fgetc(file);
      //}
    }

    if(fclose(file) != 0){
      perror("Error in closing file");
      return EXIT_FAILURE;
    }
    else{
      printf("File closed successfully.\n");
    }

    for(int i=0; i<ROWS; i++){
      for(int j=0; j<COLUMNS; j++){
        printf("%c", map[i][j]);
      }
      printf("\n");
    }
    printf("\n\n");

    while(!terminate){
      printf("Enter y & x coordinate: ");
      scanf("%d %d", &y, &x);

      if(y == -1 && x == -1){
        terminate=true;
      }
      else if(y < 0 || y > ROWS || x < 0 || x > COLUMNS){
        printf("Invalid Coordinate!\n");
      }
      else{
        if(map[y][x] == '='){
          printf("Coordinate (%d,%d) is in the sea.\n", y, x);
        }
        else{
          printf("Coordinate (%d,%d) is in the island.\n", y, x);

          countX=0;
          countY=0;

          for(int i=x; i>=0 && map[y][i]=='*'; i--){
            countX++;
          }
          for(int i=x+1; i<COLUMNS && map[y][i]=='*'; i++){
            countX++;
          }
          for(int j=y; j>=0 && map[j][x]=='*'; j--){
            countY++;
          }
          for(int j=y+1; j<ROWS && map[j][x]=='*'; j++){
            countY++;
          }

          printf("The size of island is %d x %d\n", countX, countY);
        }
      }
    }
  }

  return EXIT_SUCCESS;
}
