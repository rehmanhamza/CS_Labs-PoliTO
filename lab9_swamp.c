#include<stdio.h>
#include<stdlib.h>

#define R 5
#define C 11
#define N 15

int main(){
  char a[R][C+1];
  FILE *file;

  file=fopen("file_swamp.dat", "r");
  if(file==NULL){
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  for(int i=0; i<R; i++){
      fscanf(file, "%s", a[i]);
    }

    if(fclose(file) != 0){
      perror("Error closing file");
      return EXIT_FAILURE;
    }
    printf("Data read from file:\n\n");
    printf("\t***Swamp***\n\n");
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        printf("%c ", a[i][j]);
      }
      printf("\n");
    }
    printf("\n\n");
  /*
    **.*.*....*
    ..*.*...**.
    *.....*....
    .*.*.*.*.*.
    ..*.*...*.*
  */
      int p[N];
      int r, c;
      int i;
      int j;
      int curr_col, prev_row;

      for(i=0;i<R;i++){
        if (a[i][0] == '*'){
          curr_col = 0;
          p[curr_col] = i;
          for (curr_col = 1; curr_col < C; curr_col++){
            prev_row = p[curr_col-1];
            if (a[prev_row][curr_col] == '*'){
              p[curr_col] = prev_row;
            } else if (prev_row-1 >= 0 && a[prev_row-1][curr_col] == '*'){
              p[curr_col] = prev_row-1;
            } else if (prev_row+1 < R && a[prev_row+1][curr_col] == '*'){
              p[curr_col] = prev_row+1;
            } else {
              break;
            }
          }

          if (curr_col == C)
            break;
        }
    }

    if (curr_col == C){
      printf("Path: ");
      for (i=0;i<C;i++){
        printf("%d ", p[i]);
      }
    } else {
      printf("no path");
    }


      return 0;
  }
