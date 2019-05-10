#include <stdio.h>
#include <stdlib.h>
#define r 4
#define c 4

int main()
{
    int m[r][c];
    int i, j;
    int number=1;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            m[i][j] = 0;
        }
    }
    i=0;
    j=0;
            for (j = 0; j < c; j++) {
                m[i][j] = number++;
            }

        j--;
        for (i=1; i <r; i++) {
                m[i][j] = number++;
            }
        i--;
            for (j = 2; j >= 0; j--) {
                m[i][j] = number++;
            }
        j++;

            for (i =2; i >= 1; i--) {
                m[i][j] = number++;
            }
        i++;
        number=1;

            for (j = 1; j < 3; j++) {
                m[i][j] = number++;
            }
        j--;
            for (i = 2; i < 3; i++) {
                m[i][j] = number++;
            }
        i--;

            for (j =1; j >= 1; j--) {
                m[i][j] = number++;
            }
        j++;
            for (i=1; i>=2; i--) {
                m[i][j] = number++;
            }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
