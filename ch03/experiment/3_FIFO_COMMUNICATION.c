/*
   communication with named pipe(or FIFO)
   @author	myqiqiang
   @email	myqiqiang@gmail.com
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#define FIFO_SERVER "/home/myqiqiang/fifoserver" //fifo directioy
#define BUFFERSIZE 80
void main()
{
	pid_t pc;
	int flag,fd;
	char data[BUFFERSIZE+1];
	char* test="a test string";
	if(mkfifo(FIFO_SERVER,0777)<0)	//create fifo
	{
		printf("create named pipe failed\n");
		exit(1);
	}
	printf("create named pipe sucessfully\n");
	pc=fork();	//create process
	if(pc==0)
	{
		memset(data,0,strlen(test));
		fd=open(FIFO_SERVER,O_WRONLY);	//open the fifo
		if(fd==-1)	//if open failed
		{
			printf("write:cann't open the named pipe\n");
			unlink(FIFO_SERVER);
			exit(1);
		}
		flag=write(fd,test,13);		//write data
		if(flag==-1)	//write failed
		{
			printf("write data error\n");
			unlink(FIFO_SERVER);
			exit(1);
		}
		printf("write data successfully\n");
		close(fd);	//clsoe fifo
		unlink(FIFO_SERVER);	//delete fifo
	}
	else
		if(pc>0)
		{
			memset(data,0,strlen(test));
			fd=open(FIFO_SERVER,O_RDONLY);
			if(fd==-1)
			{
				printf("read:cann't open the named pipe\n");
				unlink(FIFO_SERVER);
				exit(1);
			}
			flag=read(fd,data,13);
			if(flag==-1)
			{
				printf("read data error\n");
				unlink(FIFO_SERVER);
				exit(1);
			}
			printf("the data is%s\n",data);
			close(fd);
			unlink(FIFO_SERVER);
		}
		else
		{
			printf("create process error!\n");
			unlink(FIFO_SERVER);
			exit(1);
		}
}
