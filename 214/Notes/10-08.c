#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define STDOUT 1
#define STDIN 0
#define STDERR 2

void sigstuff(int signum)
{

	printf("I got a segfault...w00t\n");
//	exit(-1);

	return 0;
}

int main (int argc, char ** argv)
{

//L1.
	int pid = fork();
	int status = 0;
	

	if (pid==0) {
		printf("My PID is: %d\n", getpid());
		
	}
	else {
		printf("My child's PID is: %d\n", pid);
		wait(&status);
		printf("return value = %d\n", WEXITSTATUS(status));

		printf("---------------\n");
//---------------------------------------------------

//L2.

	//Commenting this out because it creates an endless loop of segfaults by running code without updating the program counter
	// uncomment at your own risk
	//control c will kill the loop

		void (*sighandler) (int) = sigstuff;

		signal(SIGSEGV, sighandler);

		int a =*((int*)0);
		


	}


	return 0;
}



/*
Procs:
	fork()									//L1.
		- Creates a child process
		- Returns 0 to child and child's PID to parent
			- how does it return to both child and parent?
				- duplicates the entire parent Process, including execution state - stack vars, registers, etc -  so if parent is waiting for fork() to return, so is child
			- why does it return a different value to each process?
				- so the Process knows if it is the parent or the child ... so you can have the child Process do something other than what the parent was doing

				(be careful ... PIDs are not chars or unsigned ints)
		- All forked PIDs must be greater than 0
			- otherwise the child and parent would both think they are the child process
				- they would run the same code				
				- the parent would not wait for the child - @zombieorphans
				
			- PID 0 is the scheduler/init process ... not fork()ed but read directly in to memory as part of the bootstrap process



Signals:
	software interrupt .. can be caused by any type of important event
		- SIGSEGV - seg fault
		- exit
	return - returns from current funtion to caller
	exit() - terminates current context - emits EXIT signal that can be caught
	_exit() - terminates current Process - does not emit EXIT signal
		atexit

kill [pid] will kill whatever process you give the pid of

kill -9 stops all processes



*/
