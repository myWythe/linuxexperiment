/*****fifotest.c*****/
//used to test write fifo
//@author myqiqiang
//@email myqiqiang@gmail.com
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#define FIFO_SERVER "/tmp/fifoserver"

main(int argc,char**argv)
{
	int fd;
	char w_buf[4096*2];
	int real_wnum;
	memset(w_buf,0,4096*2);
	if((mkfifo(FIFO_SERVER,O_CREAT|O_EXCL)<0)&&(errno!=EEXIST))
		printf("cann't create fifoserver\n");
	if(fd==-1)
		if(errno==ENXIO)
			printf("open errno;no reading process\n");
		fd=open(FIFO_SERVER,O_WRONLY|O_NONBLOCK,0);
	real_wnum=write(fd,w_buf,2048);
	printf("real word num is %d\n",real_wnum);
	printf("errno=%d\n",errno);
	printf("errno=%d\n",EAGAIN);
	if(real_wnum==-1)
	{
		if(errno==EAGAIN)
			printf("write fifo error;try later\n");
	}
	else
		printf("real write num is %d\n",real_wnum);
	real_wnum=write(fd,w_buf,5000);
	if(real_wnum==-1)
		if(errno==EAGAIN)
			printf("try later\n");
}
