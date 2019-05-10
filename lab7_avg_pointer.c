#include<stdio.h>

#define N 5

float avgVett(int v[], int size);
int overLimit(int v[], int size, int limit);
float overAvg(int v[], int size, int *greater);

int main(){
  int v[N]={1,2,3,4,5}, size=N, limit=3, *greater=0;

  printf("Average = %f\n", avgVett(v, size));
  printf("Limit_Count = %d\n", overLimit(v, size, limit));
  printf("Over_Avg: %f\n", overAvg(v, size, &greater));

}

float avgVett(int v[], int size){
  int sum=0;
  float avg;
  for(int i=0; i<size; i++){
    sum += v[i];
  }
  avg=(float)sum/size;

  return avg;
}

int overLimit(int v[], int size, int limit){
  int count=0;
  for(int i=0; i<size; i++){
    if(v[i] > limit){
      count++;
    }
  }

  return count;
}

float overAvg(int v[], int size, int *greater){
  int sum=0, count=0;
  float avg;

  for(int i=0; i<size; i++){
    sum += v[i];
  }
  avg=(float)sum/size;

  for(int i=0; i<size; i++){
    if(v[i] > avg){
      count++;
    }
  }
  *greater=count;

  return *greater;
}
