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
Threads:
	mutexes:	MUTual Exclusion device
	
	- ensure we're accessing the correct data at the last time
	- since threads share memory, yu don't want to overwrite sensitive data
	- two threads don't access the same critical section *at the same time

	OS - too slow
	USER - can't be unblockable/uninteruptable

	one of the few times we can't have a software solution ... need hardware help ... special 'instruction' that does all steps 

	test_and_set:	sync instructions

can not sync around a memory location - must explicitly demarcate a segment of code to protect


Thread A			Thread B
				lock(mutex0)
lock(mutex0)			shared += 45
shared += 1			unlock(mutex0)
unlock(mutex0)
				lock(mutex0)
				if (shared > 100)...
				unlock(mutex0)
		

				
EXAMPLE OF BAD VERSION

THREAD A			THREAD B
lock(mutex1)			lock(mutex2)
lock(mutex2)			lock(mutex1)
shared2+= shared1;		shared2-=shared1;
unlock(mutex2)			unlock(mutex1)
unlock(mutex1)			unlock(mutex2)


	thread a locks 1
	thread b locks 2
	thread a tries to lock 2 but is blocked
	thread b tries to lock 1 but is blocked

4 things must happen for deadlock to occur
	1 - mutual exclusion	
	2 - no pre-emption
	3 - hold and wait
	4 - circular wait

circular wait - 
	1 - establish a total ordering on mutexes and ALWAYS lock in that sequence
	2 - rising/falling permission phases

WHAT NOT TO DO WITH MUTEXES:
	Health and Safety tips for your Mutex

	1 - DO NOT lock a mutex more than once in a thread without unlocking it - You Only Lock Once
		you will block yourself
	2 - DO NOT unlock a mutex more than once in a thread without locking it - You Only Unlock Once
		why tf would you do that?

(secret remedy #127)
(a double-locked mutex can not be unlocked-but it can be re-initialized) ***REALLY BAD IDEA BUT IT DOES WORK***

other mechanisms - 
	Barrier: (sync around computation) often implemented with ...
		unlike a mutex, where the first one to the mutex conntinues on and all others wait --
		all threads that hit a barrier will wait, and the last one there unlocks all
*/
