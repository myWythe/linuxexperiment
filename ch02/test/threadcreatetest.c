/*****threadcreatetest.c*****/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void* create(void* arg)
{
	printf("new thread created...");
}

int main(int argc,char* argv[])

{
	pthread_t tidp;
	int error;
	error=pthread_create(&tidp,NULL,create,NULL);
	if(error!=0)
	{
		printf("pthread_create is not created.\n");
		return -1;
	}
	sleep(1);	//if not ,the parrent process will exit before child process execute
	printf("pthread_create is created\n");
	return 0;
}
