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
	int fd = open("./someprotectedfile",O_RDWR);

	if (fd>0){		//use chmod to change permissions to try this out
		printf("Access GRANTED\n");
		close(fd);
	} else if (errno==EACCES){
		printf("Access DENIED\n");
	//	return -1;
	} else {
		printf("FATAL ERROR in file %s on line %d:\n%s\n", "someprotectedfile, );
	}


	printf("---------------\n");
//---------------------------------------------------

	fd = open(argv[1],O_RDWR);
	if (fd>0){		//use chmod to change permissions to try this out
		printf("Access GRANTED\n");
		close(fd);
	} else if (errno==EACCES){
		printf("Access DENIED\n");
	//	return -1;
	} else {
		printf("FATAL ERROR\n");
	}
	char buffer[1000];
	memset
	bzero(buffer, 1000)
	
	int bytesToRead = 1000;
	int readSoFar = 0;
	int status = 1;


	while (readSoFar < bytesToRead && status > 0)
	{

		status = read(fd, &buffer+readSoFar, bytesToRead-readSoFar);
		readSoFar += status;
	}

	printf("%d\n", status);
	printf("%s\n", buffer);

	


	return 0;
}


/*
absolute - path name starting from root .. starting with "/"
relative - path name starting from current working directory .. starting with "."

cd~ - takes you to root directory
pwd - displays direcotry URL

open("./a_file", O_RDWR) //note that is letter O, not zero.

check if open() returns -1. If it does, check errno.
If (errno == EACCES) {ERROR!!!!!!!}


touch _________  			creates a new blank file with a given name
echo "______" 				prints whatever string you give it

echo "______" > touch __________   	writes string to new/blank file
	
chmod changes file protection

a g o

w r x

all
group
owner

a > g > o

write
read
execute

chmod <type>+/-<flavor>

chmod a+r 			everybody has red permission
chmod o-w 			owner no longer has write permission
	
chmod a-w someprotectedfile	removes write permission for everybody on somerotectedfile 

ls -alF				shows permissions, accesses, creator, etc.

permissions recoreded/reported as

	 o   g   a
	 rwx rwx rwx
	 000 000 000
	 110 000 000
	 6   0   0
chmod 600 someprotectedfile	sets owner read and write permission, 
					everybody else does not have permission

chown				changes owner of file

blocking:
	you call a function - you can not continue calling the function until that call is complete
non-blocking:
	you call a function - the program continues as the function is executed
		call halts until your context until your context is swapped back in, then it immediately returns .. or .. call can return before it is entirely done

HDD latency - strongly dominated by seek time
	50ms  --> 5*10^-2

DRAM - strongly dominated by t_RC (table row access time)
	40ns  --> 4*10^-8

hard drive is nearly a million times slower than DRAM

	







 
*/
