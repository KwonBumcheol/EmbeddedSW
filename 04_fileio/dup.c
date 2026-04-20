#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;

    if((fd1 = creat("myfile", 0600)) == -1) 
        perror("myfile");

    write(fd1, "Hello! Linux\n", 13);
    fd2 = dup(fd1); // fd1 -> fd2 복제(생성)
    write(fd2, "Bye! Linux\n", 11);
    exit(0);
}