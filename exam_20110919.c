#include<stdio.h>
#include<stdlib.h>

#define N 4

int main(int argc, char *argv[]){
  if(argc != 5){
    printf("Wrong number of arguments.\n");
    return EXIT_FAILURE;
  }
  else{
    int x1, y1, x2, y2, a[N][N];

    sscanf(argv[1], "%d", &x1);
    sscanf(argv[2], "%d", &y1);
    sscanf(argv[3], "%d", &x2);
    sscanf(argv[4], "%d", &y2);

    if(x1 > N || x1 < 0 || y1 > N || y1 < 0 || x2 > N || x2 < 0 || y2 > N || y2 < 0){
      printf("Invalid coordinates!\n");
      return EXIT_FAILURE;
    }
    else{
      FILE *file;

      file=fopen("file_map.txt", "r");

      if(file==NULL){
        perror("Error opening file");
        return EXIT_FAILURE;
      }
      else{
        printf("File opened successfully.\n\n");
        for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
            fscanf(file, "%d", &a[i][j]);
          }
        }

        if(fclose(file) != 0){
          perror("Error closing file");
          return EXIT_FAILURE;
        }
        else{
          printf("File closed successfully.\n\n");
          int max_altitude=-1, min_altitude=4000, sea=0, hills=0, mountains=0, region=0, plain=0;

          for(int i=y1; i<=y2; i++){
            for(int j=x1; j<=x2; j++){
              region++;
              if(a[i][j] < min_altitude && a[i][j] > 0){
                min_altitude=a[i][j];
              }
              if(a[i][j] > max_altitude){
                max_altitude=a[i][j];
              }
              if(a[i][j] == 0){
                sea++;
              }
              if(a[i][j] > 0 && a[i][j] < 200){
                plain++;
              }
              if(a[i][j] >= 200 && a[i][j] <=600){
                hills++;
              }
              if(a[i][j] > 600){
                mountains++;
              }
            }
          }
          /*Maximum altitude: 630
          Minimum altitude: 210
          Sea: 16.67%
          Plain: 0.00%
          Hills: 50.00%
          Mountains: 33.33%*/
          printf("Maximum altitude: %d\n", max_altitude);
          printf("Minimum altitude: %d\n", min_altitude);
          printf("Sea: %0.2f\n", (sea/(float)region)*100);
          printf("Plain: %0.2f\n", (plain/(float)region)*100);
          printf("Hills: %0.2f\n", (hills/(float)region)*100);
          printf("Mountains: %0.2f\n", (mountains/(float)region)*100);
        }
      }
    }
  }

}
