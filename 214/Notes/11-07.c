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


int main (int argc, char ** argv)
{
	printf("---------------\n");
//---------------------------------------------------

	return 0;
}

/*
semaphore_produce(int * indicator, const int MAXVAL)
{
	while (*indicator >= MAXVAL) 
	{}

	*indicator = *indicator + 1;

}

semaphore_consume(int * indicator, const int MAXVAL)
{
	while (*indicator <= 0) 
	{}

	*indicator = *indicator - 1;

}


WTF is a semaphore? - old synchronization mechanism


What if sync mechanism alone are not enough due to some other imposed ordering or requirements?
	- would like to ... give all the mechanisms to someone who understands how they all relate and can protect context (threads) from deadlocking


	... need some thing that has
		- all the mechanisms (data
		- understands the dependencies between them and can allocate beased on them (i.e. functions on the data)
		- exposes data only through an interface
		- hides internal values

		OBJECT-ORIENTED Sync Supervisor: a.k.a. - Monitors


*/

