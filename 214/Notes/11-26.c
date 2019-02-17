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

status =  read(clientSocket, buffer, n);

<name>,<command>,<arg>
person,deposit,123

adsjfklgjsjsfldfadsgkjafgfgsfjg,deposit,234242414

You don't know how long the message can be
	set maximums
		max username:	255
		max command:	100
		max amount: 	100
				= 455
				round up to power of 2 = 512
_ _ _:message

read 4 chars
	maximum of 3 chars to say how long the message is
	either read first 3 chars or up to the separator, whichever comes first
	that number (minus the number of characters upto and including the separator) is the size of the message

pick RANDOM port # above 8192 and below 65000

	- build message passing client/server
		- multi-thread the client
		- multi-thread the server
	- command interface				--------\______will take longer than you expect and will be annoying
	- responses from server				--------/
	- make sure single-account works		--------\
		- mutexes				---------+-----annoyingly straight forward
		- multi-account (mutex)			--------/
	- diagnostic output (SIGALARM and semaphore)	--------\______write some code to autotest this
	- server shoutdown (SIGINT and client message)	--------/


--------------------------------------------------------------------------------------------------------

DNS	WTF is this?
	service that uses the transport layer - extra, not an inherent part of the internet

IP - networking layer

TCP & UDP - protocols at transport layer


DNS: Domain Name Service
	translates domain name into IP address

IP - Internetworking Protocol
	each network is a host
		Internet is network of networks
	Networking layer routes indirect connections using routing table
		A direct link with B
		B direct link with C
			A wants to send message to C
		IP routes A to B to C

	Routes messages from host to host
	forrms/manages indirect links out of a sequence of DL point-to-point direct links



Transport Layer Protocol
	TCP is the default protocol
		Transmission Control Protocol
		managing messaging - fast, correct, efficient...
	- psuedo-reliability - if it does not recieve confirmation from reciever-side, it will retransmit - Coordinating armies problem
		- how to know the other side got the message?
			+ have it send acknowledgment
		- how long should you wait for acknowledgment before retransmitting?
			+ TTL - Time To Live - i.e. approx. time to server/other side and back again
		- how to ick it off?
			+ RTT - Round Trip Time for first message to estimate TTL? >Connection<
			
			- client: I want to connect	(SYN) - name of connection request method
			- server: ok			(SYN-ACK) - name of connection request method - acknowledgment
			- client: yay			(ACK) - acknowledgment

			


*/

