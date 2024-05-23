#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
    int fd[2];
    size_t size;
    char string[] = "Hello, world!";
    char resstring[14];
    if(pipe(fd) < 0){
        printf("Не создается pipe\n");
        exit(-1);
    }
    size = write(fd[1], string, 14);
    if(size != 14){
        printf("Не получается создать строку\n");
        exit(-1);
    }
    size = read(fd[0], resstring, 14);
    if(size < 0){
        printf("Не получается прочитать строку\n");
        exit(-1);
    }
    printf("%s\n", resstring);
    if(close(fd[0]) < 0){
        printf("Не закрывается входной поток\n");
    }
    if(close(fd[1]) < 0){
        printf("Не закрывается выходной поток\n");
    }
    return 0;
}