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
First try to establish connection between a single client and a single server



Server
	acceptane thread
	Client handling thread

	Extra features:
		only 1 account can be created at a time (mutex protection)
		

Client
	Response thread
	Commandinput thread -- user	


Server end:

sockID = socket();
bind();
listen(sockID, backLog=5);
for(;;)
{
	newSockID = accept();

	if (fork()==0)
	{
		read(newSockID, &Data);
		write(newSockID, &Data);
		close(newSockID;
		exit;
	}
	else
	{
		continue;
	}





	
*/

