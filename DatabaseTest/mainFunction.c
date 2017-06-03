#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "myKeypadScanning.h"

int KeypadMain()
{
	int res;

	pthread_t Thread1;

	res = pthread_create(&Thread1, NULL, keypad_Thread, (void *) NULL);
	if(res!=0)
		printf("fail\n");

	while(1)
	{
		if(key_Available()==1)
			printf("gotten key = %d \n", key_Get());
	}

	pthread_join(Thread1, NULL);

	return 0;
}
