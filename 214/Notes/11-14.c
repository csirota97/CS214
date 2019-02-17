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
Socket:
	abstraction for network communications

	server:
		accepts connection request
	client:
		can connect to a server socket
		send/receive data

	server socket: 
		accept() to start listening for connection request
			returns client socket connected to the Client
		socket()
		bind()
		listen()
		accept()

	client socket:
		socket()
			*annoying bcopy from hostent in to sockaddr_in
		connect()


	read(socketfd, buffer, 100);
	write(socketfd, buffer, 100);

	  client	 server
	________	________
	|	|	|	|
	|      o|------>|o---	|
	|	|   |	|    |	|
	|_______|    -->|o<--	|
			|_______|

int newClient = accept(serverSock, ... , ... );
read(newClient, ... , ... );

accept() is blocking ... so how to server more than one client at a time?
> while blocking on accept(), can not talk to a client ... and while talking to a client, can not accept() the next connection request
	> hand off each new client socket to a thread so the server socket can get back to accept() as soon as possible

ISO OSI 7-layer stack
	Application     ----------------|
	Presentation	----------------|----can all be within the same code
	Session		----------------|
	Transport <- TCP, UDP		SOCKETS
	Networking <-IP -- Internetworking Protocol	figuring out the path of directly connected machines from start to end point
	Data Link					sends data back and forth if they are directly connected (hardwired)
	Physical					


Encapsulation - the code should be working in a black box. You don't know what is on the other end, you just assume the proper protocols are in place.
	Internet "hourglass" Architecture Model
		https://www.google.com/search?q=Internet+%22hourglass%22+Architecture+Model&tbm=isch&source=iu&ictx=1&fir=2JkHWVyOn20dIM%253A%252CHNdfqbu1LUnUgM%252C_&usg=AI4_-kRwwSMcpNh85BjrGIXxekDi2nklJw&sa=X&ved=2ahUKEwjor9rnq9XeAhWJd98KHcyiDPMQ9QEwAnoECAAQBA#imgrc=zi0UM5W7_X-z2M:

what does this mean?
	cp.cs.rutgers.edu
		it is converted to an IP address
	cp.cs.rutgers.edu > 167.26.2.4


*/

