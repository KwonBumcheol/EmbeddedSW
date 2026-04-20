#include <stdio.h>
#include <stdlib.h>

struct Pos { int x, y; };
struct Size { int width, height; };

int main() {
    struct Pos *pt = malloc(sizeof(struct Pos));    // struct Pos *pt = (struct Pos*)malloc(sizeof(struct Pos));
    struct Size *ps = pt;                           // struct Size *ps = (struct Size*)pt;

    pt->x = 320; pt->y = 240;       // == (*pt).x
    printf("pt->x = %d, pt->y = %d\n", pt->x, pt->y);    
    printf("ps->width = %d, ps->height = %d\n", ps->width, ps->height);
    free(pt);

    return 0;
}