#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){

    int n, fd1, fd2;
    char buf;
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

    while((n = read(fd1, &buf, sizeof(buf))) > 0){
        write(fd2, &buf, sizeof(buf));
    }
    if(n < 0){
        perror("Problem");
        exit(1);
    }
    close(fd1);
    close(fd2);
    return 0;
}