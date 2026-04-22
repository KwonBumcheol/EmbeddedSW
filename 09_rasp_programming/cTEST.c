#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPIO_NUMBER 17 // BCM GPIO 번호 (3-> 17 권장)

void run_pinctrl(const char *mode) {
    char command[100];
    
    sprintf(command, "pinctrl set %d %s", GPIO_NUMBER, mode);

    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: cTEST [setup|on|off|status|close]\n");
        return 2;
    }

    printf("Starting the cTEST program\n");

    if (strcmp(argv[1], "setup") == 0) {
        printf("Setting GPIO %d as output\n", GPIO_NUMBER);
        run_pinctrl("op");
    } else if (strcmp(argv[1], "close") == 0) {
        printf("Reset GPIO %d to input mode\n", GPIO_NUMBER);
        run_pinctrl("ip");
    } else if (strcmp(argv[1], "on") == 0) {
        printf("Turning ON\n");
        run_pinctrl("dh");
    } else if (strcmp(argv[1], "off") == 0) {
        printf("Turning OFF\n");
        run_pinctrl("dl");
    } else if (strcmp(argv[1], "status") == 0) {
        char command[100];

        sprintf(command, "pinctrl %d", GPIO_NUMBER);

        system(command);
    } else {
        printf("Invalid command\n");
        return 2;
    }

    printf("Finished the cTEST program\n");
    return 0;
}