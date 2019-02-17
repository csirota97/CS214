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
Review
TCP vs. UDP

Stateful vs. Stateless
	an operation is stateless if
		- the output of the function will never change for the same function call
	an operation is stateful if
		- the output of the function is determined by factors other than just the parameters

	
	read(fd, buffer, 10);	//stateful because this depends on how many times it was called previously

	printf("%s\n", "this is a string");	//stateless because it will always output the same thing


Req:		Response:
	cmd		update some data	- 
	filename	data			- scp, http server
	executable	result			- terminal/ssh

--------------------------------------------------------------------

RPC - Remote Procedure Calll
	1) local machine take commands and parameters
	2) local machine send to remote machine
	3) remote machine computes and sends back results
	4) local machine echos results recieved from remote machine

	What could some problems with this be?
		What could be a problem with sending parameters?
			- references/pointers wouldn't have access to the memory space to point to
			- a differnt machine might have a different ISA
				+ type size and format will might not be the same
			- types with structure in memory (arrays, structs, unions, ...) might be formatted differently in memory
		
		What is the most direct solution?
			- provide some type of translation
				+ i.e. an int on my side = ____, an int on your side = ____
			- use a universal protoypical language
				+ Marshalling Parameters

Marshalling Parameters:
	- flatten data types with structure
	- dereference pointers
	- translate all types into prototypical types

	**This is what Java does, which is why it is can be compiled on one machine and the executable can be run on any**
		- code is compiled into "Java Bytecode (tm)"
			+ a generic representation of assembly (rather than types)
				- a virtual machine translates the JBC to each individual machine's bytecode


Failstop		bad
	- Something that stops the code and announces what happened - i.e. segfaults
Crash			worse
	- halts and remains silent
Byzantine Faults	worst
	- non-deterministic behavior or intermittent faults




*/

