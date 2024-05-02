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
	return 0;
}
