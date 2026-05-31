#include <stdio.h>
#include <stdlib.h>

void write_file(const char *path, const char *value) {
    FILE *fp = fopen(path, "w");

    if (fp == NULL) {
        perror(path);
        exit(1);
    }

    fprintf(fp, "%s", value);
    fclose(fp);
}

int main() {
    write_file("/sys/class/leds/ACT/trigger", "none");
    write_file("/sys/class/leds/ACT/brightness", "0");

    printf("ACT LED OFF\n");

    return 0;
}