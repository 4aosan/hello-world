/*
* C test
*/
#include "hello_world.h"
#include <stdio.h>
#include <pthread.h>

int say_hello(int num)
{
	printf("[%d]Hello World\n",num); 
}

int say_goodbye(int num)
{
	printf("[%d]Good bye\n",num);
}

int main(void)
{
	pthread_t th1,th2;
	int ret=0;
    int th_ret[4]={0,0,0,0};
	func_ptr cb;

    cb = say_hello;
	th_ret[0] = pthread_create(&th1,NULL,(void *)hello_world,cb);
	cb = say_goodbye;
	th_ret[1] = pthread_create(&th2,NULL,(void *)hello_world,cb);

	th_ret[2] = pthread_join(th1,NULL);
	th_ret[3] = pthread_join(th2,NULL);
	
 	return ret;
}
