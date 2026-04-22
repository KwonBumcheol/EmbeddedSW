#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;

    // fd1 = open("myfile", WRONLY | O_CREAT | O_TRUNC, 0600); 
    if ((fd1 = creat("myfile", 0600)) == -1)
        perror("myfile");
    
    write(fd1, "Hello! Linux\n", 13);

    fd2 = dup(fd1);
    write(fd2, "Bye! Linux\n", 11);

    exit(0);
}