#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

pthread_t ntid;
pthread_mutex_t mutex;
int count;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%s pid %u tid %u (0x%x)\n",s,(unsigned int)pid,(unsigned int)tid,(unsigned int)tid);

}

void *thr_fn(void *arg)
{
	printids("new thread begin\n");
	pthread_mutex_lock(&mutex);
	printids("new thread:");
	int i = 0;
	for(;i<5;++i)
	{
		printf("thr_fn running %d\n",count++);
	}

	pthread_mutex_unlock(&mutex);
	return ((void*)100);
}

int main(void)
{
	int err;
	count = 0;
	pthread_mutex_init(&mutex,NULL);
	err = pthread_create(&ntid,NULL,thr_fn,NULL);
	if(0 != err)
		printf("can't create thread:%s\n",strerror(err));

	pthread_mutex_lock(&mutex);
	printids("main thread:");
	int i = 0;
	for(;i<5;++i)
		printf("main running %d\n",count++);
	sleep(1);
	pthread_mutex_unlock(&mutex);

	int **ret;
	pthread_join(ntid,(void **)ret);
	printf("thr_fn return %d\n",*ret);
	pthread_mutex_destroy(&mutex);
	return 0;

}

