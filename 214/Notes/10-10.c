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



void** aThread(void* stuff)
{
	printf("Thread time!\n");
	pthread_exit((void**)1);
}

void signalHandler(int signum)
{
	_exit(-1);


}

void lastBreath()
{
	printf("*GASP*\n");
	return;

}

void someOtherStuff()
{
	printf("This is some stuff\n");
	return;
}

int main (int argc, char ** argv)
{
//L1.
//	atexit(main(argc,argv));

	printf("---------------\n");
//---------------------------------------------------
//L2.
	atexit(lastBreath);

	printf("---------------\n");
//---------------------------------------------------

	int pid = fork();
	int status = 0;

	if (pid == 0)
	{
		execv("./testChild", NULL);
	}
	wait(&status);

	printf("---------------\n");
//---------------------------------------------------
//L3.
	pthread_t newThread;
	pthread_attr_t newThreadsAttrs;

	pthread_attr_init(&newThreadsAttrs);

	pthread_create(&newThread, &newThreadsAttrs, aThread, (void*)0);
	pthread_join(&newThread, (void**)1);

	return 0;
}

/*
Signals:
	Software interupts
		- subverts the FDE loop ... might interupt it entirely and have the OS take over ... unless you specified a handler for the signal .. in which case the OS causes your handler to run

		- notification of important event (not necessarily an error)


Fork():
	Creates a child process that is a duplicate of the parent
		- PID
		- Parent PID
		- Address Space

Can you call fork without exec?		yes
Can you call exec without fork?		yes

	Can NOT fork() PID0 (so it is assigned to your bootstrap proc)


Life after return(?!):
	EXIT signal happens after return, but before termination...
	atexit([funtion(...)]);
		- calls function on exit			L1. calls main on exit, causing an endless loop
								L2. calls lastBreath on exit

	IF YOU TERMINATE EXTERNALLY (from the command line, control-C) atexit() WILL NOT BE CALLED

	return	- get out of activation record
	exit() 	- get out of current context
	_exit()	- get out of process

while ... not done reading names of stuff
	......
while ... all child Procs are not yet done
	......

Threads
	- another eceution context ("thread of control") in your Proc
		- faster to build than another Proc
		- faster to switch than another Proc
		- easier to pass data to than another Proc (same as heap)

		- no separate address space (other threads can muck up your stuff while you are/are not running)
		- not a separate executable (can only run functions in THIS Proc as threads)



PTHREAD							//L3. is the code for using new threads
	- pthread_t
	- pthread_create(&[function()], );
	- use pthread_exit(1) instead of return;
	- must have "#include <pthread.h>"

*/

