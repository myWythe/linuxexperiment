//communication between parent and child process with signal
//non-block type
//@author myqiqiang
//@email myqiqiang@gmail.com
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{
	printf("recieved SIGINT signal successed!\n");
	return;
}

void main()
{
	pid_t pc;
	pc=fork();
	if(pc<0)
	{
		printf("create process error!\n");
		exit(1);
	}
	else
		if(pc==0)
		{
			printf("child process id is%d\n",getpid());
			sleep(3);
			printf("child process id is%d after the first sleep\n",getpid());
			sleep(3);
			printf("child process id is%d after the second sleep\n",getpid());
			exit(1);
		}
		else
		{
			signal(SIGINT,sigint_handler);
			pause();
		}
}
