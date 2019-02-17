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
	printf("I am a child progc\n");
	return 0;
}
/*
to compile:
	gcc testChild.c -o testChild

*/
