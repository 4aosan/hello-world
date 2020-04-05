/*
* C test
*/
#include "hello_world.h"
#include <stdio.h>
#include <pthread.h>

int main(void)
{
	pthread_t th1,th2;
	int ret=0;
    int th_ret[4]={0,0,0,0};

	th_ret[0] = pthread_create(&th1,NULL,(void *)hello_world,NULL);
	th_ret[1] = pthread_create(&th2,NULL,(void *)hello_world,NULL);

	th_ret[2] = pthread_join(th1,NULL);
	th_ret[3] = pthread_join(th2,NULL);
	
 	return ret;
}
