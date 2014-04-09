/*****waitpidtest.c*****/
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
main()
{
	pid_t pc,pr;
	pc=fork();
	if(pc<0)	//something wrong with fork
		printf("Error occured on forking!\n");
	else
		if(pc==0)	//if it's the child process 
		{
			sleep(10);//sleen 10s
			exit(0);
		}
	//if if's the parent process
	do{
		pr=waitpid(pc,NULL,WNOHANG);	//waitpid() won't here because of using the WNOhANG
		if(pr==0)	//if id didn't collect child process
			printf("No child process\n");
		sleep(1);
	}while(pr==0);	//keep trying
	if(pr==pc)
		printf("successfully get child %d\n",pr);
	else
		printf("some error occured\n");
}
