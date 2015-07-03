#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tag{
	pthread_mutex_t mutex;
	char *name;
	int value;
}my_tag;

pthread_mutex_t mutex;

void *print(void *arg)
{
	int num = 100;
	char *s = (char *)arg;
	pthread_mutex_lock(&mutex);
	for(int i = 0;i < num; i ++)
		printf("%s : %d time!\n",s,i);
	pthread_mutex_unlock(&mutex);
}

int main()
{
	my_tag *data;
	pthread_t pid1;
	pthread_t pid2;
	int status;
	//data = (my_tag *)malloc(sizeof(my_tag));
	//status = pthread_mutex_init(&data->mutex,NULL);
	pthread_mutex_init(&mutex,NULL);
	char *thread1 = "thread1";
	char *thread2 = "thread2";
	pthread_create(&pid1,NULL,print,(void *)thread1);
	pthread_create(&pid2,NULL,print,(void *)thread2);
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
	pthread_mutex_destroy(&mutex);
	//pthread_mutex_destroy(&data->mutex);
	//free(data);
	return 0;
}
