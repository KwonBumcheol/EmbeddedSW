#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    int **ptr;
    ptr = (int**)malloc(sizeof(int*) * 3);
    
    ptr[0] = (int*)malloc(sizeof(int) * 1);
    ptr[1] = (int*)malloc(sizeof(int) * 2);
    ptr[2] = (int*)malloc(sizeof(int) * 3);

    k = 0;
    for(i = 0; i < 3; i++)
        for (j = 0; j < i + 1; j++)
            ptr[i][j] = k++;
        
    for (i = 0; i < 3; i++) {
        for (j = 0; j < i + 1; j++){
            printf("ptr[%d][%d] = %d\n", i, j, ptr[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        free(ptr[i]);
    }

    free(ptr);

    return 0;
}