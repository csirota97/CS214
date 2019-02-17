#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char ** argv)
{

	struct thingy
	{
		int d;
	};

	struct stuff
	{
		int a;
		double b;
		char c;
		struct thingy oddname;
	};

	struct stuff example = {1, 1.2, 'g', {233}};

	printf("%d\n",example.oddname.d);

	printf("---------------\n");
//---------------------------------------------------

	char array0[] = "hello";
	char array1[] = "HELLO";

	printf("%d\n",array1[16]);
	printf("%c\n",array1[16]);

	array0[0] = 'y';

	printf("%c\n",array1[16]);


	printf("---------------\n");
//---------------------------------------------------


	char array2[] = "hello";
	int num = 9;
	char array3[] = "HELLO";

	printf("%d\n",array3[16]);
	printf("%d\n",sizeof(num));

	printf("---------------\n");
//---------------------------------------------------

	struct things
	{
		double b;
		long c;
		int a;
	};

	struct things junk = {1.2,1234,1};

	union thingsAlso
	{
		double b;
		long c;
		int a;
	};

	union thingsAlso moreJunk = {1.2};

	printf("sizeof(int)=%d\n",sizeof(int));
	printf("sizeof(double)=%d\n",sizeof(double));
	printf("sizeof(long)=%d\n",sizeof(long));
	printf("sizeof(junk)=%d\n",sizeof(junk));
	printf("sizeof(moreJunk)=%d\n\n",sizeof(moreJunk));

	printf("moreJunk.a=%d\n",moreJunk.a);
	printf("moreJunk.b=%f\n\n",moreJunk.b);
	
	moreJunk.a = 342;

	printf("moreJunk.a=%d\n",moreJunk.a);
	printf("moreJunk.b=%f\n\n",moreJunk.b);
	
	moreJunk.b = 3.42;

	printf("moreJunk.a=%d\n",moreJunk.a);
	printf("moreJunk.b=%f\n\n",moreJunk.b);


	printf("---------------\n");
//---------------------------------------------------

	union moreThings
	{
		double b;
		char odd[8];
		int weird[2];
	};

	union moreThings crap = {1.2};

	printf("crap char=%c\n", crap.odd[2]);
	printf("crap num=%d\n\n", crap.weird[0]);

	crap.odd[2] = 'M';

	printf("crap char=%c\n", crap.odd[2]);
	printf("crap num=%d\n\n", crap.weird[0]);

	printf("---------------\n");
//---------------------------------------------------

	int b = 0;
	int* ptr = &b;

	printf("b before increment = %d\n", b);

	increment(b);

	printf("b after increment  = %d\n", b);	
	
	increment2(&b);

	printf("b after increment2 = %d\n", b);	
	printf("---------------\n");
//---------------------------------------------------
	int array4[]= {1,2,3};
	
	int* ptra = array4;

	printf("%d\n",*array4);

	printf("%lx\n",&array4[0]);
	printf("%lx\n",&array4[1]);
	printf("%lx\n",&array4[2]);

	return 0;
}

int increment(int a) {
	a=a+1;
	return 0;
}

int increment2(int *a) {
	*a=*a+1;
	return 0;
}

/*
Review from last class:
	Why C is "better" than Java

	typedef
	structs
	enums
	
	No boolean primitive
		false=0
		true!=0
		
typedef{
	enum _boolean {true=1,false=0};
} boolean;

------------OR------------

enum _boolean {true=1, false=0};
typedef enum _boolean boolean;



struct thingy
{
	long d;
}

struct stuff
{
	int a;
	double b;
	char c;
	struct thingy oddname;
}

struct stuff example = {1, 1.2, 'g', {1}};

	typedef is not necessary, but is typically used, but if you are trying to be very clear, you can leave it out so anybody reading your code will know it is an enum/struct

	


	union
		

*/
