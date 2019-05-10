#include<stdio.h>
#include<string.h>

#define N 60
#define M 5

int main(){
  char str[N], str1[M][N], stat[N]={0};
  int words, string_length;
  float avg_length;
  printf("Enter some text:\n");
  gets(str);

  string_length=strlen(str);
  printf("\nLength of string = %d\n", string_length);

  words=sscanf(str, "%s %s %s %s %s", str1[0], str1[1], str1[2], str1[3], str1[4]);
  printf("\nNumber of words = %d\n", words);

  avg_length=(float)string_length/words;
  printf("\nThe average word length is %0.2f words.\n\n", avg_length);

  for(int i=0; i<words; i++){
    stat[strlen(str1[i])]++;
  }

  for(int i=0; i<N; i++){
    if(stat[i] != 0){
      printf("%d word(s) of %d character(s)\n", stat[i], i);
    }
  }
  /*while(str1[i] != '\0'){
    if(i==0){
      if(isalpha(str1[i])){
        words++;
      }
    }
    if((isspace(str1[i]))){
      words++;
    }

    i++;
  }
  avg_length=(float)string_length/words;

  printf("The string contains %d words.\n", words);
  printf("The average word length is %0.2f.\n", avg_length);

  for(int i=0; i<words; i++){
    stat[strlen(str1[i])]++;
  }

  for(int i=0; i<words; i++){
    printf("stat = %d, i = %d\n", stat[i], i);
  }
  /*int *each_word, j=0;
  each_word=(int *) malloc (words*sizeof(int));

  while(str1[j] != '\0'){
    if(j==0){
      if((isalpha(str1[j]))){
        each_word[j]++;
      }
    }

    j++;
  }
  for(int i=0; i<words; i++){
    printf("%d ", *(each_word+i));
  }*/

}
