#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
main()
{
	int status;
	pid_t pc,pr;
	pc=fork();
	if(pc<0)
		printf("error ocurred!\n");
	else 
		if(pc==0)
		{
			printf("This is child process with pid of %d\n",getpid());
			exit(3);
		}
		else
		{
			pr=wait(&status);
			if(WIFEXITED(status))
			{
				printf("the child process %d exit normally\n",pr);
				printf("the return code is %d\n",WEXITSTATUS(status));
			}
			else
				printf("the child process %d exit abnormally\n",pr);
		}
}
