#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
	char aString[] = {'h','e','l','l','o','\0'};
	char bString[] = "hello";
	
	printf("%s \n", aString);

	return 0;
}

/*
	C has

	int
	double
	char
	
	long
	short
	unsigned long
	unsigned int
	unsigned short

	C does NOT have Strings
	C has strings which are arrays of chars

	"array of null-terminated chars"


	'h' 'e' 'l' 'l' 'o' '\0' --> hello
	'h' 'e' 'l' 'l' 'o' --> seg fault
	'\0' is the null-terminator	

	NO BOOLEAN
	ints are commonly used instead
	0 is false
	anything other than 0 is true, but most commonly 1 is used


	enum <type name> {<value>, [value] ...}
	<   > required
	[   ] optional

	enum boolean{true, false} => true=0, false=1
	enum boolean{true=1, false=0} => true=1, false=0
	enum volumes{GALLON=32,QUART=8}
	enum colors{RED,BLUE,GREEN}

	typedef{
	enum _boolean {true=1,false=0};
	} boolean;
----is equivalent to----
	typedef enum junk boolean;

	these allow you to call "boolean" without needing to call "enum boolean"

	Arrays are collections of single types



	If you want an array of multiple types you would need a struct

	struct <name>
	{
		[values]
	};
	
	struct <name> <_name> = {[values]};

	like enum, if you typedef, you don't need to specify struct before 

	typedef struct <name1>
	{
		[values]
	}<name>;
	
	<name> <_name> = {[values]};
		
*/
