/*****signalactiontest.c*****/
/*used to test signalaction()*/
/*@author myqiqiang*/
/*@email myqiqiang@gmail.com*/
#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#define PROMPT "do you want to stop the programe?"
char* prompt=PROMPT;
void ctrl_c_op(int signo)
{
	write(STDERR_FILENO,prompt,strlen(prompt));
}

int main()
{
	struct sigaction act;
	act.sa_handler=ctrl_c_op;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(sigacction(SIGINT,&act,NULL)<0)
	{
		fprintf(stderr,"Install Signal Action Error:%s\n\a",strerrror(errno));
		exit(1);
	}
}
