#include "scannerCSVsorter.h"


record *head = NULL;
int finaltype = 0;




void BeginNewProcess(char* filename, const char* target, char* path, const char* output_dir)
{
	struct stat st = {0};
	int position = 0;
	char outputfilename[_POSIX_PATH_MAX] = {0};
	char output_directory[_POSIX_PATH_MAX] = {0};
	int filename_size = strlen(filename) + 1;
	int target_size = strlen(target) + 1;

	/* build output filename */
	strcat(outputfilename, output_dir);
	strncat(outputfilename, "/", 1);
	strncat(outputfilename, filename, filename_size);
	strncat(outputfilename, "-sorted-", 9);
	strncat(outputfilename, target, target_size);
	strncat(outputfilename, ".csv", 5);
	
	int outdirlen = strlen(output_dir)+ 1;
	strncat(output_directory, "./", 2);
	strncat(output_directory, output_dir, outdirlen);


	/* Create out ouput folder*/
	if( stat(output_directory, &st) == -1 )
	{
		mkdir(output_directory, 0700);
	}

	/* Populate Output folder */
	int fd;
	fd = creat(outputfilename, 0700);

	position = findposition(target, path);

	if(position == 0)
	{
		printf("Couldn't locate target \"%s\" input for file: [%s.csv]\n   >Exiting Child Process\n", target, filename);
		return;
	}
	
	buildlist(position, path, finaltype, outputfilename);
   	MergeSort(&head, finaltype);
   	// printList(head, finaltype, outputfilename);
   	return;
}

int 
gettype(char* target)
{
   int _int = 1;
   int _float = 2;
   int _str = 3;
   int i = 0;


   

   while(target[i] != '\0')
   {	
   		//printf("HELLO!123\n");
   		if(isalpha(target[i]) != 0)
   		{
   			return 3;
   		}
   		else if(isdigit(target[i])) //is a digit
		{
			
			while( target[i] != '\0' )
		  	{
		     	if( target[i] == '.' )
		        	return 2;

		        else if( !isdigit(target[i]) )
		        	return 3;
		        

		     	i++;
		  	}

		  	return 1;
		}
		else
			i++;
	   
	}
	  
	   
	return 0;
}

char* 
trimwhitespace(char *str)
{
   char *end;

   // Trim leading space
   while(isspace((unsigned char)*str)) str++;

   if(*str == 0)  // All spaces?
      return str;

   // Trim trailing space
   end = str + strlen(str) - 1;
   while(end > str && isspace((unsigned char)*end))
   {
      end--;
   }

   // Write new null terminator character
   end[1] = '\0';

   return str;
}


void
appendrecord(char* target, char* data)
{



	record *new_record = (record*)malloc(sizeof(record));
	record* curr = head;

	if(new_record == NULL)
	{
	  fprintf(stderr, "Unable to allocate memory for new node\n");
	  exit(-1);
	}

	if(target[0] == '\0')
	{
	  return;
	}

	char* tgt = (char*)malloc((int)strlen(target)*sizeof(char)+1);
	memcpy(tgt, target, (int)strlen(target)+1);

	char* dta = (char*)malloc((int)strlen(data)*sizeof(char)+1);
	memcpy(dta, data, (int)strlen(data)+1);

	int type = gettype(tgt);
	finaltype = type;
	new_record->target = tgt;

	if( type == 1 )
	{
	  	new_record->targetint = atoi(new_record->target);
	}
	else if( type == 2)
	{
	  	new_record->targetfloat = atof(new_record->target);
	}
	new_record->data = dta;
	new_record->next = head;
	head = new_record;

	return;
}

//void buildlist(int pos, const char* path)
void buildlist(int pos, char* path, int finaltype, char* outputfilename)
{
	int type = 0;
	int newChar = (char)0;
	int status = 1;
	
	head = (record*)malloc(sizeof(record));
	head = NULL;
	int fd = open(path, O_RDONLY, 0700);
	
	int inParenthesis = 0;
	int targetpos = 0;
	int targetsize = 100;
	int buffersize = 300;
	int attarget = 0;
	int i = 0;
	int j = 0;
	int toobigTGT = 0;
	int toobigBUF = 0;
   	int firstword = 0;
	pos = pos - 1; //adjust for comma position

	char* targetbuffer = malloc(targetsize*sizeof(char));
	char* databuffer = malloc(buffersize*sizeof(char));

	
   	if( fd == FDERROR )
	{
		printf("Failed to open file [%s]", path);
		exit(-1);
	}
	//printf("b\n");
	while( status > 0 )
	{	

		status = read(fd, &newChar, 1);
		//printf("%c", newChar);
		if( toobigBUF == 1 )
		{
			//printf("c\n");
			buffersize = buffersize + buffersize;
			toobigBUF = 0;
			databuffer = (char*)realloc(databuffer, buffersize);
			databuffer[j] = newChar;
			j++;
		}
		else
		{
			//printf("d\n");
			databuffer[j] = newChar;
			j++;
		}
		
	
		if( i >= targetsize )
			toobigTGT = 1;

		if( j >= buffersize )
			toobigBUF = 1;
		
   		// REMEMBER TRAILING AND LEADING BLANK SPACES

		if( targetpos == pos ) // if we reach our target 
   		{
			attarget = 1;
			
			
			if(( newChar == '\"' )&&( inParenthesis == 0 ))
			{
				if(toobigTGT == 1)
				{
					targetsize = targetsize + targetsize;
					toobigTGT = 0;
					targetbuffer = (char*)realloc(targetbuffer, targetsize);
				
					targetbuffer[i] = newChar;
					i++;
				}
				else
				{
					targetbuffer[i] = newChar;
					i++;
				}
				inParenthesis = 1;
				continue;
			}
			
			else if(( newChar == '\"' )&&( inParenthesis == 1 ))
			{
				if(toobigTGT == 1)
				{
					targetsize = targetsize + targetsize;
					toobigTGT = 0;
					targetbuffer = (char*)realloc(targetbuffer, targetsize);
				
					targetbuffer[i] = newChar;
					i++;
				}
				else
				{
					targetbuffer[i] = newChar;
					i++;
				}
				inParenthesis = 0;
				continue;
			}
			
			if(( newChar == ',' )&&( inParenthesis == 0 ))
			{
				attarget = 0;
				targetpos++;
			}
			else
			{
				if( toobigTGT == 1 )
				{
					targetsize = targetsize + targetsize;
					toobigTGT = 0;
					targetbuffer = (char*)realloc(targetbuffer, targetsize);
				
					targetbuffer[i] = newChar;
					i++;
				}
				else
				{
					targetbuffer[i] = newChar;
					i++;
				}
				
			}

   		}
		else if( newChar == '\"' ) // if current char is parenthesis
		{

			if( inParenthesis == 0 )  // if a starting parenthesis
				inParenthesis = 1;
			else 					// if a closing parenthesis
				inParenthesis = 0;  

		}
		else if( newChar == ',' ) //if the current char is a comma
   		{

			if( inParenthesis == 0 ) //if not inside parentheis
			{
				targetpos++;  //increase target position
			}
   			
   		}
		else if( newChar == '\n' )
		{

			targetbuffer[i] = '\0';
			databuffer[j] = '\0';

			inParenthesis = 0;
			targetpos = 0;
			targetsize = 100;
			buffersize = 300;
			attarget = 0;
			i = 0;
			j = 0;
			toobigTGT = 0;
			toobigBUF = 0;

			if(firstword == 0)
			{
				firstword = 1;
				continue;
			}
			char* newtarget = trimwhitespace(targetbuffer);
			char* newdata = trimwhitespace(databuffer);

			//printf("[%s]",newtarget);

			// targetbuffer = realloc(newtarget, strlen(newtarget)+1);
			// databuffer = realloc(newdata, strlen(newdata)+1);

			appendrecord(newtarget, newdata);
		}
   		
   	}
   	close(fd);
	free(targetbuffer);
   	free(databuffer);

   	printList(head, finaltype, outputfilename);
   	free(head);
	return;
}

//int findposition(char* target, const char* path)
int findposition(const char* target, char* path)
{
	int targetsize = (int)strlen(target);
	// printf("Target: %s\n", target);

	//path = trimwhitespace(path);
	//printf("Path: %s\n", path);

	char newChar = (char)0;

	int size = 420;
	//printf("Path Path Path Path: %s\n", path);
	int fd = open(path, O_RDONLY , 0700);
	
	if( fd == FDERROR )
	{
		printf("Failed to open file");
		perror("Error: ");
		exit(-1);
	}

	int j = 0;
	int check = 0;
	int verify = 0;
	int increment = 0;
	int position = 0;
	//printf("Targetsize: %d\n", targetsize);

	while( newChar != '\n' )
	{

		read(fd, &newChar, 1);
		//printf("%c", newChar);

		if(newChar == ',')
		{
			increment++;
			//printf("%d\n", increment);
		}
		
		if(check == 1)
		{
			if(newChar == ',' || isspace(newChar))
			{
				
				verify = 1; 
				position = increment;
				// printf("Verify!\n");
				// printf("pos: %d\n", increment);
			}
			else
			{
				// printf("Failed!\n");
				check = 0;
				j = 0;
			}
		}

		if(verify != 1){
			if(newChar == target[j])
			{
				j++;
				// printf("Match #%d\n", j);

				if(j == targetsize)
				{
					check = 1;
					// printf("Check!\n");
				}
			}
			else
			{
				j = 0;
			}
		}
	}

	if(close(fd) < 0)
	{
		perror("c1");
		exit(1);
	}
	// printf("closed the fd.\n");

	return position;
}

int TraverseDirectory(char* curr, int indent, const char* target, const char* outputdir, int OGPID, int status)
{
	int k = 0;
	int* pids;
	int blurb = 0;

	struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(curr);
    
	if (pDir == NULL) 
	{
        printf ("Cannot open directory '%s'\n", curr);
        exit(0);
    }
    
    pid_t child_pid, wpid;
    char* newpath = (char*)calloc(512, sizeof(char));
    int starting_dir = 1;
    
    while((pDirent = readdir(pDir)) != NULL) 
    {	
    	
    	char path[_POSIX_PATH_MAX] = {0};

    	if(pDirent->d_type == DT_DIR)
    	{   
    		if(strcmp(pDirent->d_name, ".") == 0 )
    		{
    			if(starting_dir == 1)
    			{
    				starting_dir = 0;
    				strcat(newpath, curr);
    				strncat(newpath, "/", 1);
    				trimwhitespace(newpath);

    			}
    			else
    			{
    				strncat(newpath, "/", 1);
    			}
    			continue;
    		}
    		else if(strcmp(pDirent->d_name, "..") == 0 || strcmp(pDirent->d_name, ".git") == 0)
			{
				continue;
			}
			else
			{
				pid_t dirpid = fork();
				if(dirpid == 0)
				{
					status = 0;
					int nplen = strlen(newpath);
					int pdlen = strlen(pDirent->d_name);

					if((nplen + pdlen) >= 512)
					{
						newpath = (char*)realloc(newpath, nplen + 100);
					}
					strcat(newpath, pDirent->d_name);
					status = TraverseDirectory(newpath, indent, target, outputdir, OGPID, status);
					return status;
				}
				else
					blurb++;
			}
    	}
    	else
    	{
    		int i = 0;
    		while(pDirent->d_name[i] != '\0')
    		{
    			if(pDirent->d_name[i] == '.')
    			{
    				i++;
    				if(pDirent->d_name[i] == 'c')
    				{
    					i++;
    					if(pDirent->d_name[i] == 's')
    					{
    						i++;
    						if(pDirent->d_name[i] == 'v')
    						{
    							i++;
    							if(pDirent->d_name[i] == '\0')
    							{
    								i = i - 4;
    								
									char* newnewpath = (char*)calloc(512,sizeof(char));
									int nnplen = strlen(newpath);
									int ppdlen = strlen(pDirent->d_name);

									if((nnplen + ppdlen) >= 512)
									{
										newpath = (char*)realloc(newpath, nnplen + 100);
									}
									strncat(newnewpath, newpath, nnplen);
									strncat(newnewpath, pDirent->d_name, ppdlen);
									pDirent->d_name[i] = '\0';
									BeginNewProcess(pDirent->d_name, target, newnewpath, outputdir);
									free(newnewpath);
									break;
    							}
    						}
    					}
    				}
    			}
    			i++;
    		}
    	}
    	
    }
    closedir(pDir);
    printf("blurb1: %d\n", blurb);
    while((wpid = wait(&status))> 0)
    {
    	printf("*#*#Y %d\n", WEXITSTATUS(status));
    	printf("%d ", wpid);
    	blurb += WEXITSTATUS(status);
    }

    if(getpid() == OGPID)
    	printf("\n\nTotal number of processes: %d\n", blurb + 1);
	
	free(newpath);
	printf("blurb: %d\n", blurb);
   	return blurb;

}

int 
main(int argc, char** argv)
{
	struct stat st = {0};
	int OGPID = getpid();
	int totalpids = -1;

	// printf("*============================================================*\n");
	// printf("||                       		                    ||\n");
	// printf("||                       Scanner-Sorter                     ||\n");
	// printf("||                           			            ||\n");
	// printf("*============================================================*\n");



	printf("Initial PID: %d\n\n", OGPID);
	printf("PIDS of all child processes: \n");

	if( stat("./Output", &st) != -1 )
	{
		printf("Error: Directory ./Output already exists\n   >Exiting Program.\n");
		exit(0);
	}
	if(argc < 3)
	{
		printf("Invalid number of Parameters (Too Few)\n   >Exiting the Program\n");
		exit(0);
	}
	if(argc > 7)
	{
		printf("Invalid number of Parameters (Too many)\n   >Exiting the Program\n");
		exit(0);
	}
	if(strcmp(argv[1], "-c") != 0)
	{
		printf("The first Flag Parameter is \"%s\". It should be \"-c\"\n   >Exiting Program.\n", argv[1]);
		exit(0);
	}
	
	
	if(argc == 3)
	{
		totalpids = TraverseDirectory(".", 2, argv[2], ".", OGPID, 0);
	}

	else if(argc == 4)
	{
		if(strcmp(argv[3], "-d") == 0)
		{
			totalpids = TraverseDirectory(".", 2, argv[2], ".", OGPID, 0);
		}
		else
		{
			printf("Second Flag Paramter \"%s\" is Incorrect\n   >Exiting Program.\n", argv[3]);
			return -1;
		}
	}
	
	else if(argc == 5)
	{
		if(strcmp(argv[3], "-d") == 0)
		{
			totalpids = TraverseDirectory(argv[4], 2, argv[2], ".", OGPID, 0);
		}
		else if(strcmp(argv[3], "-o") == 0)
		{
			totalpids = TraverseDirectory(".", 2, argv[2], argv[4], OGPID, 0);
		}
		else 
		{
			printf("Second Parameter \"%s\" is incorrect (-d or -o)\n   >Exiting the Program\n", argv[3]);
			exit(0);
		}
		
	}

	else if(argc == 6)
	{
		if(strcmp(argv[3], "-d") != 0)
		{
			printf("Second Parameter \"%s\" is incorrect (Must be -d))\n   >Exiting the Program\n", argv[3]);
			exit(0);
		}
		else if((strcmp(argv[3], "-d") == 0)&&(strcmp(argv[4], "-o") == 0)&&(argv[5] != NULL))
		{

			totalpids = TraverseDirectory(".", 2, argv[2], argv[5], OGPID, 0);
			
		}
		else if((strcmp(argv[3], "-d") == 0)&&(strcmp(argv[5], "-o") == 0))
		{
			totalpids = TraverseDirectory(argv[4], 2, argv[2], ".", OGPID, 0);

		}
		else 
		{
			printf("Error: (Six Parameters entered)\n   >Exiting Program\n");
			exit(0);
		}
		
	}


	else if(argc == 7)
	{
		if((strcmp(argv[3], "-d") == 0 )&&(strcmp(argv[5], "-o") == 0 ))
		{
			totalpids = TraverseDirectory(argv[4], 2, argv[2], argv[6], OGPID, 0);
		}
		else if((strcmp(argv[3], "-d") == 0 )&&(strcmp(argv[5], "-o") != 0 ))
		{
			printf("Third Flag Parameter\"%s\" is not correct\n   >Exiting the Program\n", argv[5]);
			return -1;
		}
		else if((strcmp(argv[3], "-d") != 0 )&&(strcmp(argv[5], "-o") == 0 ))
		{
			printf("Second Flag Parameter\"%s\" is not correct\n    >Exiting the Program\n", argv[3]);
			return -1;
		}
		else if((strcmp(argv[3], "-d") != 0 )&&(strcmp(argv[5], "-o") != 0 ))
		{
			printf("Second Flag Parameter\"%s\" and Third Flag Parameter \"%s\"is not correct\n   >Exiting the Program\n", argv[3], argv[5]);
			return -1;
		}
		else if((strcmp(argv[3], "-o") != 0 )&&(strcmp(argv[5], "-o") != 0 ))
		{
			printf("Second Flag Parameter\"%s\" and Third Flag Parameter \"%s\"are not correct (Duplicate -o Flags)\n   >Exiting the Program\n", argv[3], argv[5]);
			return -1;
		}
		else if((strcmp(argv[3], "-d") != 0 )&&(strcmp(argv[5], "-d") != 0 ))
		{
			printf("Second Flag Parameter\"%s\" and Third Flag Parameter \"%s\"are not correct (Duplicate -d Flags)\n   >Exiting the Program\n", argv[3], argv[5]);
			return -1;
		}
		else
		{
			printf("Unknown Error\n   >Exiting the Program.\n");
			return -1;
		}
			
	}


   	return totalpids;
}
