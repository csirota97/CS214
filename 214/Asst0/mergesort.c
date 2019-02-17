#include "Merge.h"


/*
	For string arrays, call "divideStr(array, 0, size);"
	For double arrays, call "divideDbl(array, 0, size);"
	For long arrays, call "divideLng(array, 0, size);"
*/
int main(int argc, char* argv) {
	char* in1[] = {"This", "Is", "A", "Test", "Array", "For", "My", "MergeSort"};
	long in2[]= {5,3,7,4,8,4,2,1};
	double in3[]= {5.5,32.4,7.2,42.4,87.0,43.5,2.1,18.1};
	int size = 8;

	int test[size];

//To test any of the mergeSort calls, uncomment the divide___() function and the corresponding print loop 

//	divideStr(in1,0,size-1); 		//string	
//	divideLng(in2, 0, size-1);		//long
//	divideDbl(in3, 0, size-1);		//double

/*	for (size=8; size>0;size--){		//string
		printf("%s\n",in1[8-size]);
	}
*//*	for (size=8; size>0;size--){		//long
		printf("%ld\n",in2[8-size]);
	}
*//*	for (size=8; size>0;size--){		//double
		printf("%f\n",in3[8-size]);
	}
*/
	return 0;

}

void divideStr (char* list[], int left, int right)
{
	if (left<right)
	{
        	int mid = left+(right-left)/ 2;
			
		divideStr(list, left, mid);
		divideStr(list, mid + 1, right);

		mergeStr(list, left, mid, right);
	}
}

void mergeStr (char** list, int left, int mid, int right)
{
	int i=0;
	int j=0;
	int m = mid+1;
	int k=left;
	
	char* temp1[mid-left+1];
	char* temp2[right-mid];

	for (i = 0; i < mid-left+1; i++)
	{
		temp1[i] = list[left + i];
	}
	
	for (j = 0; j < right-mid; j++)
	{
		temp2[j] = list[m+ l];
	}
	
	i = 0;
	j = 0;

	while (i < mid-left+1 && l < (right+left)/2+1)
	{
		if (strcmp(temp1[i], temp2[l]) <= 0 )
		{
			list[k] = temp1[i];
			i++;
		} 
		else
		{
			list[k] = temp2[j];
			j++;
		}
		k++;
	}
	
	while (i < mid-left+1)
	{
		list[k] = temp1[i];
		i++;
		k++;
	}
	
	while (l < right-mid)
	{
		list[k] = temp2[l];
		j++;
		k++;
	}
}


void divideLng (long list[], int left, int right)
{
	int i;

	if (left<right) 
	{
		divideLng(list,left, (left+right)/2);
		divideLng(list,((left+right)/2)+1, right);
	}
		mergeLng(list,left, ((left+right)/2), right);
}

void mergeLng (long list[], int left, int mid, int right)
{
	long temp[right];
	int l;
	int m;
	int i;

	for(l = left, m = mid + 1, i = left; l <= mid && m <= right; i++) {
		if(list[l]< list[m])
		{
			temp[i] = list[l];
			l++;
		}
		else
		{
			temp[i] = list[m];
			m++;
		}
	}
   
	while(l <= mid)    
	{
		temp[i]= list[l];
		l++;i++;
	}
	while(m <= right)       
	{
		temp[i] = list[m];
		l++;m++;
	}

	for(i = left; i <= right; i++)
	{
		list[i] = temp[i];
	}
}


void divideDbl (double list[], int left, int right)
{	
	int i;
	

	if (left<right) 
	{
		divideDbl(list,left, (left+right)/2);
		divideDbl(list,((left+right)/2)+1, right);
		mergeDbl(list,left, ((left+right)/2), right);
	}
}

void mergeDbl (double list[], int left, int mid, int right)
{
	double temp[right];
	int l;
	int m;
	int i;

	for(l = left, m = mid + 1, i = left; l <= mid && m <= right; i++) {
		if(list[l]< list[m])
		{
			temp[i]=list[l];
			l++;
		}
		else
		{	
			temp[i]=list[m];
			m++;
		}
	}
   
	while(l <= mid)    
	{
		temp[i]=list[l];
		l++;i++;
	}
	while(m <= right)       
	{
		temp[i]=list[m];
		l++;m++;
	}

	for(i = left; i <= right; i++)
	{
		list[i] = temp[i];
	}
}


