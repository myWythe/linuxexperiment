#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
static int shdata=4;
void* create(void* arg)
{
	printf("new thread...\n");
	printf("shared data=%d\n",shdata);
	return(void*)0;
}
int main(int arg,char*argv[])
{
	pthread_t tid;
	pid_t pc;
	pc=pthread_create(&tid,NULL,create,NULL);
	if(pc!=0)
	{
		printf("thrad is not created\n");
		exit(-1);
	}
	sleep(3);
	printf("thread created successfully\n");
	return 0;
}
