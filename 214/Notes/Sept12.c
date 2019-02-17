#include "Sept12.h"

int main (int argc, char ** argv)
{

	int array0[] = {1,3,5};
	int *stuff0 = array0;
	printf("%d\n",*stuff0);
	printf("%d\n",*array0);
	printf("%d, stuff at array, 1, plus 2 = 3\n",(*array0)+2);//stuff at array, 1, plus 2 = 3
	printf("%d, add 2*size of element to the address\n",*(array0+2));//add 2*size of element to the address

	double array1[] = {1.1,3.3,5.5};
	printf("%f\n", *(array1+2));

	printf("---------------\n\n");
//---------------------------------------------------

	int i = 0;

	while (i<3) {
		printf("%f\n", *(array1+i));
		i++;
	}

	printf("---------------\n\n");
//---------------------------------------------------
	
	stuff1 stuff1a = {1,2.2}; 					//defined in Sept12.h

	printf("{%d, %f}\n", stuff1a.a, stuff1a.b);
	printf("SOMEINT,SOMEDOUBLE = {%d, %f}\n", SOMEINT, SOMEDOUBLE); //defined in Sept12.h

	printf("---------------\n\n");
//---------------------------------------------------
	
	printf("SQUARE(SOMEINT)=%d\n", SQUARE(SOMEINT));
	printf("SQUARE(SOMEINT+SOMEINT)=%d\n\n", SQUARE(SOMEINT+SOMEINT));
	printf("SQUARE1(SOMEINT)=%d\n", SQUARE1(SOMEINT));
	printf("SQUARE1(SOMEINT+SOMEINT)=%d\n", SQUARE1(SOMEINT+SOMEINT));

	printf("---------------\n\n");
//---------------------------------------------------
	
//	char* inputStuffA[10]; //what if you try to add an 11th item? 
//	char* inputStuffB[11]; //what if you try to add an 12th item?...
//	char* inputStuffX[10000000000]; //in theory, you can do it but it takes WAY to much memory, for potentially only a few chars
	char inputStuff0[10];
	char* inputStuff1 = (char*)malloc(10*sizeof(char));//because we want space for 10 chars with each taking up 1 byte	
//inputStuff0 and inputStuff1 are the same size

	inputStuff0[0] = 'a';

	if (inputStuff1 == NULL) {
		printf("PANIC!\n");
		return -1;
	}

	*inputStuff1 = inputStuff0[0];
	 
	printf("%c\n", inputStuff1[0]);

	free(inputStuff1);
	




	return 0;
}

/*
double a =23.13431;
double* addressOfa = &a;

int array[] = {1,2,3};
int *stuff = array;
printf("%d\n",*array);

be very careful with #define. It can do weird things that break PEMDAS.

#ifndef is a conditional definition that trips if the name has not been used.
	must end file with #endif


*/

