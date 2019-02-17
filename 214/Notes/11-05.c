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
Asst 2 FAQ:
	outputs 1 file - sorted outputs of ALL CSVs
	what if the files have different headers - must be able to handle nulls



DEADLOCK: **This looks mighty examable**
	0 - Mutual Exclusion
	1 - No pre-emption
	2 - Hold and Wait
	3 - Circular Wait

Op code:
	test_and_set -> auutomatically test a shared indicator variable to see if it indicates another context is in the critical section ... if not, set it 
		- lends itself well to locks, implemented in Pthread library as mutexes
		- used to protect data ... sunc around code that touches shared space

What not to do with mutexes:
	Double lock
	DOuble unlock

0 - Total ordering on all mutexes
1 - Rising/Falling permission phases

mutex: first one there passes through, any others who reach it at the same time must wait ... once the first unlocks it, only the next proceeds
	resolves in order of arrival
barrier: all threads that arrive at the barrie wait for the last one to make it ...  once they are all there, they are all released
	implemented with a fetch_and_increment instruction


mutexes: often used to sync around data					(test_and_set)
barrier: often used to sync around computation				(fetch_and_increment)
?: often used to sync around ?
	what else might you want to sync around or wait for?
		IO?
		Time?
		Instructions?
	
		* (other stuff)
	condition variable: often used to sync around system events	(compare_and_swap)
		
Presume: accessing a mutex in a signal handler
	0 - mutexes are sensitive to ordering ... and the signal can occur at any time, causing you to double-lock, double-unlock, unlock before lock, etc.
	1 - mutexes are sensitive to identity ... and the signal can occur in any context
		(signals are Proces-level events, and the signal handler is run by whatever context your Process is currently executing)
			DO NOT USE MUTEXES IN A SIGNAL HANDLER
		if thread A locks mutex 2, and then thread B tries to unlock mutex 2, it won't be able to
		
Mutexes are 100% not Threadsafe ... if you want to use a sync mechanism in a signal handler, alongside threads, it needs to be
	0 - insensitive to identity - threadsafe
	1 - insensitive to ordering - asynchronous

*/

