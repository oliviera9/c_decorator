#include <stdio.h>
#include "shm.h"

extern struct A gpios;

void *shmget()
{
	// simulate shared memory
	return (void *)&gpios;
}

int shmdt(void *shm)
{
	printf("shm detached\n");
	// release shared memory
	return 0;
}