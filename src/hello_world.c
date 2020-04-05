/*
* hello.world.c
*/
#include "hello_world.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> /* usleep*/
#include <stdlib.h> /* rand*/

int hello_world(void)
{
	pthread_t tid;
	tid = pthread_self();
	int i;
	int usleep_time;
	for(i=0; i<10; i++){
		srand(i);
		usleep_time=(int)(rand()%6+1);
		printf("[%d:%d]hello world !\n",tid,i);
		usleep(usleep_time);
	}
}

