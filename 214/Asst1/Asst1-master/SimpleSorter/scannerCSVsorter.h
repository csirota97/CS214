
#ifndef SIMPLESCSVSORTER_H
#define SIMPLESCSVSORTER_H


#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define FDERROR -1


#endif

#ifndef _POSIX_PATH_MAX
#define _POSIX_PATH_MAX 512
#endif


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <sys/wait.h>


int gettype(char*);

struct _record
{
	char* target;
	char* data;
	int targetint;
	double targetfloat;
	struct _record* next;
};
typedef struct _record record;

struct _output
{
	int original_pid;
	int pids[255];
	int total_processes;
	struct _output* next;
};
typedef struct _output output;


//Suggestion: prototype a mergesort function
record* SortedMerge(record*, record*);

void FrontBackSplit(record*, record**, record**);

void MergeSort(record**, int);

char* trimwhitespace(char *);
void appendrecord(char* , char* );
int gettype(char*);
void printList(record*, int, char*);
void buildlist(int , char*);
int findposition(const char* , char* );
void TraverseDirectory( char* , int , const char*, output* , const char*);
void BeginNewProcess(char* , const char* , char*, const char* );

