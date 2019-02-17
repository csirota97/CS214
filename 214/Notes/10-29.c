#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>,
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
Threads:
	an execution context in a process in addition to the main one (i.e. multi-stack process)

User threads:
	only user knows about it
	user schedules it to run
	build a stack in dynamic memory, update stack pointer to point to it and jmp to its first instruction
		(implement a scheduler, set an alarm signal and make the signal handler handle your schedule)

	+ total control
	+ faster to build
	+ faster to swap between
	+ don't lose runtime optimizations
	- no true simultaneity
		blocking call in a user-thread will block all user-threads in the process

Kernel threads:
	kernel knows about thread
	kernel schedules it to run
	
	... opposite of above...

pthread_create(thread_handle, pointer to thread attributes, functionForThreadToRun, functionArgs*);
pthread_exit(void* retval);
pthread_join(pthread_t, void** retval);	// similar to wait(&status) for processes
	
kernel threads are default

terminology
	critical section - CS - a section of code which reads or writes shared data
		synchronize code before and after critical sections
		if one thread is accessning shared data, no other thread can access that part of the code
	race condition - potential for interleaved execution of a critical section by multiple threads
	mutual exclusion - synchronization mechanism to avoid race condition by ensuring exclusive execution of critical sections
	deadlock - permenant blocking of threads
	livelock - 
	starvation - 

How to provide mutual exclusion?:
OS?
	has full control over all the stuff
	it is the one scheduling in the first place... so it can choose not to  swap a thread out if it is in a critical section
	it can not be interrupted
	
	not a bad idea, but really slow in practice
User?
	Set a global status/flag variable to indicate if a shared area is in use
		- be sure to check it before accessing shared area
		- if not in use, set it equal to 'in use'
		- when done, reset it
	
		not a bad idea, but it is the same problem as shared memory to begin with...can still have thread colliding on read/write

	Need:
		- a way to make read, compare, and write to global variable a  transaction
		     -> A|tomic -> need 3 instructions to happen 'at once'
			C|onsistency
			I|solation
			D|urability

		NO SOFTWARE SOLUTION:
			Add an opcode to:
				do each of the three steps at once
					- first check the indicator
					- then, if not used
						- set it to used state
			Add an opcode to:
				do each of the three steps at once
					- get the indicator
					- set to not used state

		test-and-set -> locking -> mutexes
			pthread_mutex_init(...)
			pthread_mutex_destroy(...)			
			pthread_mutex_lock()		//included in pthread library
			pthread_mutex_unlock()


Thread 1		Thread 2
lock(mutexA)		lock(mutexA)
CP+=10			CP-=5
unlock(mutexA)		unlock(mutexA)				

*/

