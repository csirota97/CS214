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
Do not test on same machine

Turn this one off:
	set valueto 0

	z = setsockopt(s,
		SOL_SOCKET,
		SO_LINGER,
		&so_linger,
		sizeof so_linger);

Break glass if needed:		//very dangerous
	z= setsockopt(s,
		SOL_SOCKET,
		SO_REUSEADDR,
		&so_reuseaddr,
		sizeof so_reuseaddr);

	&(int*){1}


pthread_cond_timedwait(pthread_cond_t *restrict cond,
		      pthread_mutex_t *restrict mutex,
		      const struct timespec *restrict abstime);

must use itimer on server side

------------------------------------------------------------------------------------------------


ISO OSI 7-layer stack
	Application     ----------------|
	Presentation	----------------|----can all be within the same code
	Session		----------------|
	Transport <- TCP, UDP		SOCKETS
	Networking <-IP -- Internetworking Protocol	figuring out the path of directly connected machines from start to end point
	Data Link					sends data back and forth if they are directly connected (hardwired)
	Physical


Packets - Transport layer (msg<-->packet)
TCP - 
	(port)
	"Reliability"		- retry sends of packets whose delivery timed out
	Ordering		- deliver packets in orders, regardless of how they arrive
	Flow Control		- throttle rate of packet sending due to endpoint
	Congestion Control	- throttle rate of packet sending due to network

UDP - 
	(port)


Why would you use UDP is TCP has so many more features?
	- Less overhead
	- Faster
	
TCP - Stateful
	retains information on packets sent/recieved, timing, etc.
	information that is not in the parameters affects what happens/how things work

UDP - Stateless
	at least it has a port, right?
	only information in the parameters affects what happen/how things work

read(fd, buffer,10);
	Stateful or Stateless?

	Stateful
		consider the following:
			read(fd, buffer,10);	//reads first 10 bytes
			read(fd, buffer,10);	//reads where previous statement left off. Filehandler, although part of the FileDescriptor, is not in the parameters 



Cookies - 
	A keypair - a key information storage
	The serverside will ask you to store information
		when you reaccess that domain, it sends the information back


--------------------------------------------------------------------------------------------


Why do we care about state?
	

what can you send across the network?
	resources - data
		send a byte from client, read a byte from socket
	commands
		send bytes from client, read in bytes ?
	computation
	

Distributed System
	multiple machines cooperating, giving the illusion of single endpoint, but it isn't

Why distribute?
	performance
		instead of going deep, spread everything out
		a large website can't handle all of the traffic, google, for example, will route a user to any of thousands of machines in order to handle load
	avaiability
		there is one path out of australia and it sucks, have a localized host
	reliability
		if one machine goes down, the service won't go down


*/

