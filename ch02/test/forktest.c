/*****forktest.c*****/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
	int i;
	int p_id;
	if(p_id=fork()==0)
	{
		/*child process*/
		for(i=1;i<3;i++)
			printf("This is child process\n");
	}
	else
		if(p_id==-1)
		{
			printf("fork new process error!\n");
			exit(-1);
		}
		else
		{
			/*parent*/
			for(i=1;i<3;i++)
				printf("This is parent process\n");
		}
}
