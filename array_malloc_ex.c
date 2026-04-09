#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    int **ptr = (int**)malloc(sizeof(int*) * 3);

    for(i = 0; i < 3; i++)
        ptr[i] = (int*)malloc(sizeof(int) * 4);

    k = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            ptr[i][j] = k++;
        }
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("ptr[%d][%d] = %d\n", i, j, ptr[i][j]);
        }
    }

    for(i = 0; i < 3; i++) {
        free(ptr[i]);
    }

    free(ptr);

    return 0 ;
}