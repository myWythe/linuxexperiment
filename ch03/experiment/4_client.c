/*
  uesd to build a link between server and client with FIFO
  client file
  @author myqiqiang
  @email myqiqiang@gmail.com
*/

#include"csfifo.h"
int main(int argc,char* argv[])
{
	int fd,flag;
	char r_msg[BUFSIZ];
	char* temp="client message to server";
	char* cf="/home/myqiqiang/cfifo";
	char* s_msg;
	char* cfifo;

	if(argc!=2)
	{
		printf("Usge:./client n \n");
		return 0;
	}
	s_msg=malloc(strlen(temp)+strlen(argv[1])+sizeof(char));
	cfifo=malloc(strlen(cf)+strlen(argv[1]));
	strcpy(s_msg,argv[1]);
	strcpy(cfifo,cf);
	s_msg[strlen(argv[1])]='#';
	strcat(s_msg,temp);
	strcat(cfifo,argv[1]);

	if(mkfifo(CSFIFO,0777)<0)
	{
		perror("cann't create fifo\n");
		return 0;
	}
	fd=open(CSFIFO,O_RDWR,0);
	if(fd==-1)
	{
		perror("cann't open FIFO\n");
		return 0;
	}
	flag=write(fd,s_msg,strlen(s_msg));
	if(flag==-1)
	{
		printf("cann't write data to the FIFO:\n");
		return 0;
	}
	else
	{
		printf("write data successfully\n");
	}
	while(1)
	{
		sleep(3);
		if(open(cfifo,O_RDONLY)<0)
		{
			printf("FIFO cfifo hasn't been created,please wait a while\n");
			sleep(3);
			continue;
		}
		fd=open(cfifo,O_RDONLY,0);
		if(fd==-1)
		{
			perror("cann't open FIFO:\n");
			return 0;
		}
		flag=read(fd,r_msg,strlen(r_msg));
		if(flag==-1)
		{
			printf("read data error\n");
			return 0;
		}
		else
		{
			printf("%s",r_msg);
			return 0;
		}
	}
}
