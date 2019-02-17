#include "09-24.h"

int main (int argc, char ** argv)
{
	printf("---------------\n");
//---------------------------------------------------

	return 0;
}


/*
Assignment:

chars to watch out for:
	'\n'
	','
	'"'
	' '

comparator:
	take in 2 things
	return an int corresponding to their relative order

int comparator(void* param0, void* param1)
	returns:
		-1: param0>param1
		0: param0=param1
		1: param0<param1


int (*comparator)(void*, void*)	//functionpointer



typedef
struct_Node
{
	?* data;
	Node* next
} Node;

int generalizedSort (void* data, int (*comparatorFn)(void*, void*))
{
	Node* listHead = dataList;

	int result = comparatorFN(listHead->data, listHead->next->data);

	...if necessary, swap nodes, if not, yay!...continue

	return 0;
}

int comparatorFn_INT(void* param0. void* param1)
{
	if(*((int)param0)>*((int)param1))
		return -1;
	else if(*((int)param0)<*((int)param1))
		return 1;
	return 0;
}
int comparatorFn_DBL(void* param0. void* param1)
{
	if(*((double)param0)>*((double)param1))
		return -1;
	else if(*((double)param0)<*((double)param1))
		return 1;
	return 0;
}

int comparatorFn_STRING(void* param0. void* param1)
{
	return strcmp((char*)param0,(*char)param1);
}

How to tell if end of file:
	if read returns 0, file is over

Blocking and Nonblocking

Computation parts:	fast
IO parts:		SSSSSSLLLLOOOOOOOOOOOOOOWWWWWWWWW
	

2GHz ->	2*10^-9
60ms ->	6*10&-2

//Blocking IO --- your code will not continue past the IO call until it is done
int a = 2+3;
write(fd, &a, 4);
a++;

//Non-blocking --- your code will return immediately at the beginning of the next time slice and tell you how much it does


char data[10];

int status = 0;
int reaIn = 0;
int total = 0;

while (status > 0)
{
	status = read(STDIN, data+readIn,total);
	readIn += status;
	total -= status;
}

char buffer = '\0'

while (status > 0)
{
	status = read(STDIN, &buffer,1);
}
*/
