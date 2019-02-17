#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>

#define STDOUT 1
#define STDIN 0
#define STDERR 2

#define Size 15
#define File "testText.txt"

void * simple_func(void * arg)
{
	printf("THREAD#: %d!\n", *((int*)arg) );


	int * retval = (int*)malloc(sizeof(int));
	*retval = 100;

	pthread_exit((void*) retval);
}

int main (int argc, char ** argv)
{
//L1.
///	pthread_t * newThread = (pthread_t*)malloc(sizeof(pthread_t));	//Proper way to create thread handle
//	pthread_create(newThread
	pthread_t newThread;						//quick and dirty way

	pthread_attr_t newAttrStruct;					//Creates pthread struct

	pthread_attr_init(&newAttrStruct);				//initializes pthread struct

	int *threadArg = (int*)malloc(sizeof(int));
	*threadArg = 1;
	
	int **retThread;
	
	pthread_create(&newThread, &newAttrStruct, simple_func, (void*) threadArg);
	pthread_join(newThread, (void**)retThread);

	printf("%d\n", **retThread);

	free(threadArg);
	free(*retThread);

	printf("---------------\n");
//---------------------------------------------------

	return 0;
}

/*
Forks - not easy to share pointers between because they do not share the same address space
Threads - easy to share pointers between because they are just 2 (or more) stacks which share the same address space


non-blocking
|-------------|+++++++++++|***********|+|---------s	

asynchronous
|-------------|$$$|----|*********************|---------|**********|----^------|
		 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

blocking
|------|+++++++++|***************|+++++++++++++|




L1.

Threads :
	If you don't need address protection, signal handling, etc. it might make more sense to make a new thread instead of a new process

	faster to build/swap between than procs
	easier to pass data between than procs

	int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start routine) (void*), void*	arg)
				^			^			^				^
			pointer to pthread	 thread attributes	function to run			  function args

	pthread_attr_init(pthread_attr_t *attr)
	pthread_attr_destroy(pthread_attr_t *attr)

	int pthread_join(pthread to join, returnValue)
	int pthread_detach(pthread to detach)

different types of threads:
	kernel threads:
		scope: system
		-longer to build
		-longer to swap between
		-not much control over scheduling
		+true simultaneity
		+blocking calls DO NOT halt all threads
	user threads:
		scope: user
		+faster to build
		+faster to swap
		+full control over scheduling
		-no true simultaneity
		-blocking calls DO halt threads
	
*/

