/*****wordcount*****/
#include<stdio.h>
#include<pthread.h>
#include<ctype.h>

pthread_mutex_t counter_clock=PTHREAD_MUTEX_INITIALIZER;
int total_words=0;

int main(int ac,char* av[])
{
	int pc;
	pthread_t t1,t2;
	void*count_words(void*);
	if(ac!=3)
	{
		printf("Usage:%s file1 file\n",av[0]);
		exit(1);
	}
	pc=pthread_create(&t1,NULL,count_words,av[1]);
	if(pc!=0)
	{
		printf("thread created error!\n");
		exit(0);
	}
	pc=pthread_create(&t2,NULL,count_words,av[2]);
	if(pc!=0)
	{
		printf("thread created error!\n");
		exit(0);
	}
	pc = pthread_join(t1,NULL);
	pc = pthread_join(t1,NULL);
	printf("total words in %s and %s are %d\n",av[1],av[2],total_words);
}

void* count_words(void* f)
{
	char*filename=(char*)f;
	FILE*fp;
	int c,prevc='\0';

	if((fp=fopen(filename,"r"))!=NULL)
	{
		while( (c = fgetc(fp))!=EOF)
		{
			if(!isalnum(c) && isalnum(prevc))
			{
				pthread_mutex_lock(&counter_clock);
				total_words++;
				pthread_mutex_unlock(&counter_clock);
			}
			prevc=c;
		}
		fclose(fp);
	}
	else
	{
		printf("open file %s error!\n",filename);
	}
	return NULL;
}
