#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define STDOUT 1
#define STDIN 0
#define STDERR 2

int main (int argc, char ** argv)
{
	int pid = fork();	//similar to malloc :: free
	int status = 0;

	if (pid==0) {
		execv("./testChild", NULL);
	}

	wait(&status);		//similar to free :: malloc	deallocates memory from child once child is done running

	printf("---------------\n");
//---------------------------------------------------

	return 0;
}


/*
i-nodes - 
	stores:
		metadata
		pointers to data
	basically works like a linked list of data in memory

	generic data structure


p-nodes - pointer nodes
	struct to represnt running code -- emphasis on runnING code
		How does code 'run' (./)?	FDE LOOP!!!!
			Fetch - 
				get value from program counter, load instruction from memory
				program counter - holds address of next instruction

					(load)

			Decode -
				determine instruction type and format
				resolve memory and cache references

					(latch)

			Execute - 
				perform the operation and increment the program counter
		

	Process struct needs to hold - 
		Process Control Block (OS Management Structure)
			ID, owner, permissions	//not necessary if computer runs one process at a time
		Process Struct Needs To Hold
			instructions
			data
				stack
				heap

How do processes run?
	fork(void);	//duplicates current process	//creates child process
		returns child processor ID to parent
			if pid == 0, return
	exec();		//creates new process
	kill();		//ends process
*/
