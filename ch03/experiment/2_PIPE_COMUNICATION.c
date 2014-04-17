/*
   communication with pipe
   @author	myqiqiang
   @email	myqiqiang@gmail.com
*/
#include<wait.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define MAX_LINE 80
void main()
{
	int thePipe[2],ret;
	pid_t pc;
	char buf[MAX_LINE+1];
	const char*testbuf="a test buf";
	if(pipe(thePipe)==0)	//if create pipe successfully
	{
		pc=fork();
		if(pc==0)	//if create child process sucessfullly
		{
			close(thePipe[1]);	//close the write port
			sleep(3);	//sleep a while
			ret=read(thePipe[0],buf,MAX_LINE);	//read data through pipe and put in buf
			if(ret>0)
			{
				printf("chile process read data successfully\n");
				printf("the data is %s\n",buf);
			}
			close(thePipe[0]);	//close the read port
			exit(1);
		}
		else
			if(pc>0)	//parent process 
			{
				close(thePipe[0]);
				ret=write(thePipe[1],testbuf,strlen(testbuf));	//wtite data to the pipe from testbuf
				if(ret>0)
					printf("parent process write pipe sucessfully\n");
				close(thePipe[1]);
				printf("parent process clsoe the pipe port sucessfully\n");
				sleep(3);
			}
			else
			{
				printf("chile process create error!\n");
				exit(1);
			}
	}
	return;
}
