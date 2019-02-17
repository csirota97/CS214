#include "scannerCSVsorter.h"


double sigmoid(double x)
{
	double exp_value;
	double return_value;

	exp_value = exp((double)-x);

	return_value = 1 / (1 + exp_value);
	printf("Sigmoid: %f\n",return_value);
	return return_value;
}

void printList(record* headref, int type, char* outputfilename) 
{ 

	int fd = open(outputfilename, O_CREAT| O_WRONLY | O_APPEND , 0700);
	//printf("HERE?\n");
	while(headref != NULL) 
	{ 
		write(fd, headref->data, (int)strlen(headref->data));
		
		//printf("%s\n", headref->data); 
		headref = headref->next;
		write(fd, "\n", 1);
	} 
	close(fd);

	// double average = 0.0;
	// int i = -1;

	// if(type == 3)
	// {
	// 	while(headref != NULL) 
	// 	{ 
	// 		printf("%s\n", headref->target); 
	// 		headref = headref->next; 
	// 	} 
	// }
	// else if(type == 1)
	// {
	// 	while(headref != NULL) 
	// 	{ 
	// 		printf("[%d]\n", headref->targetint); 

			
	// 		if( i == -1) 
	// 		{
	// 			average = (double)headref->targetint;
				
	// 			//printf("%d. Average: %f\n", i, average);
				
	// 		}
	// 		else
	// 		{
	// 			average = ((average * i)+ (double)headref->targetint)/(i+1);
				
	// 			//printf("%d. Average: %f\n", i, average);
				
	// 		}
	// 		i++;
	// 		headref = headref->next; 
			
	// 	} 

	// 	i--;
	// 	printf("\n-----------------\n");
	// 	printf("Average: %f\n", average);
	// 	printf("-----------------\n");
	// }
	// else if(type == 2)
	// {
	// 	// double sig = 0.00000;
	// 	// int i = 0;
	// 	// double threshold = 7.50000;
	// 	int imdb = 0;
	// 	while(headref != NULL)
	// 	{ 
			
	// 		printf("[%f]\n", headref->targetfloat);
	// 		//sig = sigmoid(headref->targetfloat);
	// 		if(headref->targetfloat >= 7.5)
	// 		{
	// 			i++;
	// 		}
	// 		headref = headref->next;

	// 	}

	// 	printf("\n-----------------\n");
	// 	printf("[For imdb_score only]\nNumber of imdb_scores greater than 7.5: %d\n",i);
	// 	printf("-----------------\n");
	// }

} 

int compareString(char*,char*,int, int);
int compareString(char* first, char* second, int len_1, int len_2)
{

	int output = 0;
	int fix_len= len_2>=len_1 ? len_1 : len_2;
	int iter1=0;
	int iter2=0;
	
	while(iter1<=fix_len || iter2<=fix_len)
	{
		if(first[iter1] == '\"')
		{
			iter1++;
		}
		if(second[iter2] == '\"')
		{
			iter2++;
		}

		if(tolower(first[iter1]) != tolower(second[iter2]))
		{
			if(tolower(first[iter1])>tolower(second[iter2]))
			{
				output = -1;
				break;
			}
			else
			{
				output = 1;
				break;
			}
		}
		iter1++;
		iter2++;
		

	}
	
	// if(iter == fix_len)
	// {
	// 	if( iter < len_1 )
	// 	{
	// 		output = -1;
	// 	}
	// 	else if(iter < len_2)
	// 	{
	// 		output = 1;
	// 	}
	// 	else
	// 	{
	// 		output = 0;
	// 	}
	// }
		
	return output;
}

record* 
Merge(record* first, record* second, int type) 
{ 
	
	  
	/* Base cases */
	if (first == NULL) 
	    return second; 
	else if (second == NULL) 
	    return first; 
	else
	{
		int x, y, a, b = 0;
		
		record *i, *j, *tmp, *headref;
		i = first;
		j = second;

		
		

		int comp = 0;

		if(type == 3)
		{
			if(i->target != NULL && j->target == NULL)
			{
				comp = 1;
			}
			
			else if(i->target != NULL && j->target != NULL)
			{
				
				a = (int)strlen(i->target) + 1;
				b = (int)strlen(j->target) + 1;
				comp = compareString(i->target,j->target, a,b);
				
				
			}
			else if(i->target == NULL && j->target == NULL)
			{
				comp = 1;
			}
			else
			{
				comp = -1;
			}
		}
		

		
		/* Pick either first or second, and recur */
		if(type == 1){

			if ( i->targetint <= j->targetint)
			{
				headref = i;
				i = i->next;
			}
			else
			{ 
			    headref = j;
			    j = j->next;
			} 
		}
		else if(type == 3)
		{
			if ( comp >= 0)
			{
				headref = i;
				i = i->next;
			
			}
			else
			{ 
			    headref = j;
			    j = j->next;
			} 
		}

		else if(type == 2){

			if ( i->targetfloat <= j->targetfloat)
			{
				headref = i;
				i = i->next;
			}
			else
			{ 
			    headref = j;
			    j = j->next;
			} 
		}
		


		

		tmp = headref;

		while(i != NULL && j != NULL)
		{
			
			
			if(type == 3)
			{
				if(i->target != NULL && j->target == NULL)
				{
					comp = 1;
				}
				
				else if(i->target != NULL && j->target != NULL)
				{
					
					a = (int)strlen(i->target) + 1;
					b = (int)strlen(j->target) + 1;
					comp = compareString(i->target,j->target, a,b);
					
					
				}
				else if(i->target == NULL && j->target == NULL)
				{
					comp = 1;
				}
				else
				{
					comp = -1;
				}
			}
			
			if(type == 1)
			{
				if( i->targetint <= j->targetint)
				{
					tmp->next = i;
					tmp = tmp->next;

					i = i->next;
				}
				else
				{
					tmp->next = j;
					tmp = tmp->next;

					j = j->next;
				}
			}
			else if(type == 3)
			{

				if( comp >= 0)
				{
					tmp->next = i;
					tmp = tmp->next;

					i = i->next;
				}
				else
				{
					tmp->next = j;
					tmp = tmp->next;

					j = j->next;
				}
			}
			else if(type == 2)
			{
				if( i->targetfloat <= j->targetfloat)
				{
					tmp->next = i;
					tmp = tmp->next;

					i = i->next;
				}
				else
				{
					tmp->next = j;
					tmp = tmp->next;

					j = j->next;
				}
			}
			
		}
		if(i == NULL)
			tmp->next = j;
		else
			tmp->next = i;

		return headref;
	
		
		
		
	}

	
} 

void 
Partition(record* headref, record** frontRef, record** backRef) 
{ 
	
    record* fast; 
    record* slow; 

    slow = headref; 
    fast = headref->next;
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast->next != NULL) 
    { 
    	//printf("fast: (%s) ", fast->target);
		fast = fast->next; 

		if (fast->next != NULL) 
		{ 
		
		    slow = slow->next; 
		    fast = fast->next; 
		} 

    } 
  	
    /* 'slow' is before the midpoint in the list, so split it in two 
    at that point. */
    *frontRef = headref; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 

void 
MergeSort(record **headref, int type)
{
	//printf("%d\n", type);
	if( *headref == NULL || (*headref)->next == NULL)
		return;
	
	record* first;
	record* second;

	Partition(*headref, &first, &second);

	/* Recursively sort the sublists */
	MergeSort(&first, type); 
	MergeSort(&second, type); 
	  
	/* answer = merge the two sorted lists together */
	*headref = Merge(first, second, type);

	
}