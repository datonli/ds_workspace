#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

typedef struct tag
{
	pthread_mutex_t mutex;
	int value;
	string name;
} my_tag;

void *add_thread(void *arg)
{
	/*
	my_tag *my_arg = (my_tag *) arg;
	int num = my_arg->value;
	string name(my_arg->name);
	pthread_mutex_t &pmutex = my_arg->mutex;
	*/
	string name("thread");
	int num = 100;
	int status = 0;
	//status = pthread_mutex_lock(&pmutex);
	for(int i = 0;i < num; i ++)
	{
		cout << name + " : " << i <<endl;
	}
	//status = pthread_mutex_unlock(&pmutex);
}

int main(void)
{	
	my_tag *data,*data2 ;
	int status = 0;
	pthread_t pid_add1 = 0,pid_add2 = 0;

	data = (my_tag *) malloc(sizeof(my_tag));
	status = pthread_mutex_init(&(data->mutex),NULL);
	if(status != 0)
		cout << "pthread_error\n" <<endl;

	data->value = 100;
	data->name = "thread1";

	//status = pthread_create(&pid_add1,NULL,add_thread,(void *)data);
	status = pthread_create(&pid_add1,NULL,add_thread,NULL);
	if(status != 0)
		cout << "create thread1 faild!\n" << endl;

	data2 = (my_tag *) malloc(sizeof(my_tag));
	data2->value = 200;
	data2->name = "thread2";
	status = pthread_mutex_init(&(data2->mutex),NULL);
	//status = pthread_create(&pid_add2,NULL,add_thread,(void *)data2);
	status = pthread_create(&pid_add2,NULL,add_thread,NULL);
	if(status != 0)
		cout << "create thread2 faild!\n" << endl;

	pthread_join(pid_add1,NULL);
	pthread_join(pid_add2,NULL);
	pthread_mutex_destroy(&data->mutex);
	pthread_mutex_destroy(&data2->mutex);
	free(data);
	free(data2);
	return 0;
}
