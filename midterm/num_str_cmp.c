#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 100

char lineptr1[MAXLINES];
char lineptr2[MAXLINES];

int strcmp(const char *, const char *);
int numcmp(const char *, const char *);

int main(int argv, char *argc[]) {
    int choice;

    while(1) {
        printf("Enter: 1 (number), 2 (string), and 0 (exit): ");
        scanf("%d", &choice); // 1, 2, 0

        if (choice == 0)  // 0
            return 0;
        
        printf("Enter the two inputs: ");
        scanf("%s", lineptr1); // 20201524
        scanf("%s", lineptr2); // 3020
        
        // 코드 작성
        if (choice == 1) {
            numcmp(lineptr1, lineptr2);
        } else if (choice == 2) {
            strcmp(lineptr1, lineptr2);
        }
    }
    return 0;
}

int strcmp(const char *string1, const char *string2) {
    char s1[8], s2[4];
    for (int i = 0; i < 8; i++) {
        s1[i] = string1[i];
    }
    for (int i = 0; i < 4; i++) {
        s2[i] = string2[i];
    }

    if (s1[0] > s2[0]) {
        printf("%s가 %s보다 먼저입니다.", s1, s2);
        return -1;
    } else if (s2[0] > s1[0]) {
        printf("%s가 %s보다 먼저입니다.", s2, s1);
        return 1;
    } else {
        return 0;
    }
}

int numcmp(const char *s1, const char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);

    // 코드 작성
    // 1
    if (v1 > v2) {
        printf("%d가 %d보다 먼저입니다.", v1, v2);
    } else if (v2 > v1) {
        printf("%d가 %d보다 먼저입니다.", v2, v1);
    }

}