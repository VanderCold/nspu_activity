#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	int semid;
	char pathname[] = "key.ipc";
	key_t key;
	struct sembuf mybuf;
	if((key = ftok(pathname, 0)) < 0) {
		printf("Генерация не удалась\n");
		exit(-1);
	}
	if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
		printf("Дескриптор массива семафора не получен\n");
		exit(-1);
	}
	mybuf.sem_op = -1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	if(semop(semid, &mybuf, 1) < 0) {
		printf("Операция над семофором не произведена\n");
		exit(-1);
	}
	printf("Условие разблокировки выполнено!!!!\n");
	return 0;
}