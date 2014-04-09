#include<errno.h>
#include<error.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
char command[256];

void main()
{
	int rtn;	//return value from the child process
	while(1)    //read comond from the terminal
	{
		printf(">");
		fgets(command,256,stdin);
		command[strlen(command)-1]=0;
		if(fork()==0)	//child process execute
		{
			execlp(command,command);
			perror(command);
			exit(-1);
		}
		else			//parrent process execute
		{
			wait(&rtn);
			printf("child process return %d\n",rtn);
		}
	}
}


