/*****waittest1.c*****/
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	pid_t pc,pr;
	pc=fork();
	if(pc<0)	//something wrong
		printf("error occured!\n");
	else 
		if(pc==0)
		{
			printf("This is child process with pid of %d\n",getpid());
			sleep(10);
		}
		else
		{
			pr=wait(NULL);
			printf("I catched i child process with pid of %d\n",pr);
		}
	exit(0);
}
