/*****siginttest.c*****/
//used to test sigemptyset(),sigfillset(),sigaddset(),sigdelset(),sigismember() and sigprocmask()
//@author myqiqiang
//@email myqiqiang@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

//choose you function to handle SIGINT,if Ctrl+c are paused,printf something rather not quiting

void my_SIGINT_func()
{
	printf("if you wnat to quit,please try 'Ctrl+\\'.\n");
}

int main()
{
	sigset_t set;
	struct sigaction action1,action2;
	//initialize the set to be empty
	if(sigemptyset(&set)<0)
	{
		perror("sigemptyset");
		exit(1);
	}
	//add signal to the signal set
	if(sigaddset(&set,SIGQUIT)<0)
	{
		perror("sigaddset SIGQUIT");
		exit(1);
	}
	if(sigaddset(&set,SIGINT)<0)
	{
		perror("sigaddset SIGINT");
		exit(1);
	}
	//set the signal block word
	if(sigprocmask(SIG_BLOCK,&set,NULL)<0)
	{
		perror("sigprocmask SIG_BLOCK");
		exit(1);
	}
	else
	{
		printf("blocked,and sleep for 5s...\n");
		sleep(5);
	}
	if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
	{
		perror("sigprocmask SIG_UNBLOCK");
		exit(1);
	}
	else
	{
		printf("unblock\n");
		sleep(2);
		printf("if you want to quit this programe,please try...\n");
	}
	//circulate handling the signal
	while(1)
	{
		if(sigismember(&set,SIGINT))
		{
			sigemptyset(&action1.sa_mask);
			action1.sa_handler=my_SIGINT_func;
			sigaction(SIGINT,&action1,NULL);
		}
		if(sigismember(&set,SIGQUIT))
		{
			sigemptyset(&action2.sa_mask);
			//chose the defaule way to handle SIG_DEL
			action2.sa_handler=SIG_DFL;
			sigaction(SIGTERM,&action2,NULL);
		}
	}
	return 0;
}
