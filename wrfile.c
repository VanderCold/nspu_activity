#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int fd;
	size_t size;
	char string[] = "Knee-deep in the Dead";
	if((fd = open("DOOM.txt", O_WRONLY|O_CREAT, 0666)) < 0) {
		printf("too bad\n");
		exit(-1);
	}
	size = write(fd, string, 21);
	if(size != 21) {
		printf("Не удалось записать 21 байт\n");
		exit(-1);
	}
	else printf("Строка записана\n");
	if (close(fd) < 0) {
		printf("Не получилось закрыть\n");
		exit(-1);
	}
	char resstring[21];
	if((fd = open("DOOM.txt", O_RDONLY)) < 0) {
		printf("Ошибка записи для чтения\n");
		exit(-1);
	} 
	size = read(fd, resstring, 21);
	if (size != 21) {
		printf("epic failure\n");
		exit(-1);
	}
	else printf("Всё получилось: %s\n", resstring);
	if (close(fd) < 0) {
		printf("Не получилось закрыть\n");
		exit(-1);
	return 0;
	}
	return 0;
}
