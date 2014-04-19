/*
  uest to create link between server and customer with FIFO
  server file
  @author myqiqiang
  @email myqiqiang@gmail.com
*/
#include"csfifo.h"

int main(int argc,char*argv[])
{
	char* buf;
	int fd,flag,word_num,number;
	char* clientfifo="/home/myqiqiang/cfifo";

	while(1)
	{
		if(mkfifo(clientfifo,0777)<0)
		{
			perror("client hasn't created the FIFO!\n");
			sleep(4);
			continue;
		}
		fd=open(CSFIFO,O_RDONLY,0);
		if(fd=-1)
		{
			perror("open fifo error!\n");
		}
		if(read(fd,buf,1024)==-1)
		{
			printf("cann't read data from the FIFO!\n");
			return;
		}
		else
		{
			printf("the data is %s\n",buf);
			close(fd);
			word_num=strlen(buf);
			char*str=calloc(word_num,sizeof(char));
			strcpy(str,buf);
			number=atoi(str);
			if(number==0)
			{
				printf("Don't read any data from the client\n");
				return;
			}
			printf("%d\n",number);
		}
	}
}
