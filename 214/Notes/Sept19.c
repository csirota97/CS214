#include "Sept19.h"

int main (int argc, char ** argv)
{
	char buffer[]="howdy!\n";
	char buffer2[]="ERROR!\n";
	write(STDOUT ,buffer,7);		//write
	write(STDERR, buffer2, 7);		//error
	printf("---------------\n");
//---------------------------------------------------

	char buffer3[10];
	read(STDIN, buffer3, 10);
	write(STDOUT, buffer3, 10);
	printf("\n");
	printf("---------------\n");
//---------------------------------------------------
	
	printf("%d\n",mergesort(1));

	return 0;
}

/*
File Descriptors:
	Abstraction for IO
	
	Open
	Close

	Read
		read to 0 => Standard input => Define in header
	Write
		write to 1 => Standard Output => Define in header
	Error
		write to 2 => Standard Error => Define in header

Standard Input:
	command line input, once code is running

UNIX COMMANDS:


	cat [OPTION]...[FILE]...
	cat test.c
**output**
#include "test.h"
...
}
	cat [FILENAME] > [FILENAME2]   ==> dumps all of FILENAME into FILENAME2
	cat test.c | ./a.out > NewFile ==> takes the output of a.out with test.c as input and puts that in NewFile

	more [OPTION]...[FILE]...
	cat test.c
**output**
#include "test.h"
...
}
			breaks up file to readable ammouts


	less [OPTION]...[FILE]...
	cat test.c
**output**
#include "test.h"
...
}
			breaks up file to readable ammouts, even more than "more"



	> 	creates new file or overwrites existing file
	>>	creates new file of appends to existing file
	
	
LIBRARIES
	make another C file with functions
	UNIX code:
		gcc -c Sept19Lib.c
	creates:
		Sept19Lib.o
	
	Compile:
		gcc Sept19.c Sept19Lib.o

AUTOMATE THAT SHIT WITH A MAKEFILE
	must be named either:
		Makefile
		makefile
	<directive>: [requirement]...
		<cmd>

	default directives:
make ==> if you don't give a directive, it will look for "all"

all: test.c testlib.o
	gcc test.c testlib.o

testlib.o: testlib.c
	gcc -c testlib.c

clean: 
	rm a.out testlib.o
*/

