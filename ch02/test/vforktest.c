/*****vforktest.c*****/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
	int data=0;
	pid_t pid;
	int choose=0;
	while((choose=getchar())!='q')
	{
		switch(choose)
		{
			case'1':
				pid=fork();
				if(pid<0)
					printf("Error");
				if(pid==0)
				{
					data++;
					exit(0);
				}
				wait(pid);
				if(pid>0)
					printf("data ia %d\n",data);
				break;
			case'2':
				pid=vfork();
				if(pid<0)
					perror("Error!\n");
				if(pid==0)
				{
					data++;
					exit(0);
				}
				wait(pid);
				if(pid>0)
					printf("Data is %d\n",data);
				break;
			default:
				break;
		}
	}
}
