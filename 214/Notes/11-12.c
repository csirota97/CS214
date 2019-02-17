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
Not reliable way to debug codes

pthread_t me = ...;
printf("%d\n", me ...);

minimize contention:
	don't have one linked list
____________________________________

Monitors
	- object-oriented sync supervisors
	- avoid deadlock ... but ... why? - more contention -> slower
		(could global ordering and rising/falling phases to avoid it ... so why the extra resources and contention?)
		> because if you can not do global ordering due to resource dependencies (machine requirements/protocols/system operation/implementation), the best you can do is encode those dependencies in to the monitor's allocation logic so it can know if you are headed for a deadlock or not and allocate appropriately

		> also used for network communication
			- socket
				+ client socket
					- can connect to server socket
					- can also send/recieve bytes of data
				+ server socket
					- accept client connections
						- when getting a new connection request:
							- construct a new 'client' socket on this side to talk to the connection socket
							- send acknowledgement to connecting socket to let it know the connection is good
							- "nothing...there is no third thing"

			*C is old. Networking is ugly but once you do it once or twice, it gets better


Building Sockets:
	- server socket
		socket()	// build sockets
		bind()		// weld socket to a given port - more about this later
		listen()	// this socket will only listen ... no talky
		accept()	// start listening for connection requests...

	- client socket
		socket()	// build socket
		connnect()	// connect to server socket

2 annoying data structures you need to use
	- hostent
	- sockaddr_in


***Must include <sys/types.h> and <sys/socket.h>***

	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	while ( sockfd < 0)
	{
		error("ERROR opening socket");
	}

	bzero((char*) &serverAddressInfo, sizeof(serverAddressInfo));
	serverAddressInfo.sin_port = hton(portno);
	serverAddressInfo.sin_family = AF_INET;
	serverAddressInfo.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockfd, (struct sockaddr*) &serverAddressInfo, sizeof(serverAddressInfo)) < 0)
	{
		error("ERROR on binding")
	}

	listen(sockfd,5);

	clilen = sizeof(clientAddressInfo);

	newsockfd = accept(sockfd, (struct sockaddr*) &clientAddressInfo, &clilen);


	// If we are here, a client tried to connect

	
--------------------------
client side
	serverIPAddress = gethostbyname(argv[1]);	//can give domain as string or IP
	if (serverIPAddress == NULL)
	{
		//error
	}

*/
