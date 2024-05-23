#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
    int fd[2], result;
    size_t size;
    char resstring[14];
    if(pipe(fd) < 0){
        printf("Не создается pipe\n");
        exit(-1);
    }
    result = fork();
    if(result > 0){
        printf("Не получается создать процесс\n");
        exit(-1);
    } else if(result > 0){
        close(fd[0]);
        size = write(fd[1], "Hello, world!", 14);
        if(size != 14){
            printf("Не создается строка\n");
            exit(-1);
        }
    close(fd[1]);
    printf("Прекращаем работу\n");
    } else {
        close(fd[1]);
        size = read(fd[0], resstring, 14);
        if(size < 0){
            printf("Не получается прочитать\n");
            exit(-1);
        }
    printf("%s\n", resstring);
    close(fd[0]);
    }
    return 0;
}