//communication between parent and child process with signal
//block type
//@author myqiqiang
//@email myqiqiang@gmail.com
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<wait.h>

void sigchld_handler(int sig)
{
	pid_t pid;
	int status;
	for(;(pid=waitpid(-1,&status,WNOHANG))>0;)
	{
		printf("child %d died:%d\n",pid,WEXITSTATUS(status));
		printf("hi,parent process recieved SIGHLD signal successfully!\n");
	}
	return;
}

void main()
{
	pid_t pc;
	pc=fork();
	if(pc==0)
	{
		printf("child process id is %d\n",getpid());
		sleep(5);
		exit(SIGCHLD);
	}
	else
		if(pc>0)
		{
			signal(SIGCHLD,sigchld_handler);
			pause();
		}
		else
			if(pc<0)
			{
				printf("process create error!\n");
				exit(1);
			}
}
