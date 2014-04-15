/*****experiment_1,new process*****/
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
main()
{
	pid_t pc,pr;
	char str[20];
	pc=fork();
	if(pc<0)
	{
		printf("new process failed\n");
	}
	else
		if(pc==0)
		{
			FILE*fp;
			fp=fopen("test.txt","r");
			fgets(str,20,fp);
			printf("%s\n",str);
			sleep(1);
			exit(0);
		}
		else
		{
			waitpid(pc,NULL,0);
			printf("parrent process\n");
		}
}
