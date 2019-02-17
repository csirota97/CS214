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

server:
	socket()
	bind()
	listen()
	accept()

client:
	socket()
	connect()



-------------------------------------

TCP:
	reliability(?)
		 message------->
			<-------acknowledge
	TTL~RTT
	Time To Live --> Approximated with Round Trip Time

	how to kick-start RTT? ... have a 'handshake' (0th message) to test the connection
		use the connection request method
			send connection request and then watch the clock and wait

		---SYN--->		__
			<---SYN-ACK---	__|--time this take to get back to client is RTT
		---ACK--->		-----user data
	
		Messages should not be too big
			if one bit is lost/corrupted during transmission, the whole thing will need to be retransmitted
			+ fast
			+ little delay
			- high risk
			- likely need to be resent

		Messages should not be too small
			it will take to long to send and wait for acknowledgement on each bit
			+ low risk
			- slow

		How big should messages be?

Delivering Data
	circuit-switching:
		set-up/address once, all data goes to same place
	packet-switching:
		set-up/address each message, piece of data might take a different route

	
"Hello out there in the Intertubes"

192.1.68.1:20"hello out

192.1.68.1:20 there in t

192.1.68.1:20he Intertubes"

	if the packets aren't recieved in order, you could get:

 there in t"hello outhe Intertubes"

	Ordering - sequence numbering and packet ACKs
		packet-switching sets a number for each message so you won't get that garbage

		You don't want to send packets that are too big or too small
			if it is too small the meta-data be much bigger than the data itself.

	Big packets are likely to have errors and need to be resent.
		What should TCP do to make sure there are less packets needing to be resent?
			SMALLER PACKETS - takes longer, but less error prone


Congestion Control

Flow Control
	slows network if congested in network or at endpoint

TCP:
	Reliability
	Ordering
	Congestion Control
	FLow Control
	
UDP:
	...at least it gives you a port to work with...


*/

