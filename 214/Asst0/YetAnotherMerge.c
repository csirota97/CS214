#include "Merge2.h"



int main(int argc, char* argv) {
	char* input[] = {"This", "Is", "A", "Test", "Array", "For", "My", "MergeSort"};
//	char* input[] = {"This", "Butt", "Toes", "Deba", "Sits", "Shit", "Pits", "Fits"};
	long ir[]= {-1,2,6,3,5,4,7,8};
	int size = 8;

	int test[size];
	mergeSort(input, 0, size);
	int i;
	for (i=1; i<=size;i++){
		printf("%s\n",input[i]);
	}

	return 0;
}


void mergeSort(char* list[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;
			
        // Sort first and second halves
        mergeSort(list, l, m);
        mergeSort(list, m + 1, r);

	int i;

        merge(list, l, m, r);
    }
}

void merge(char* list[], int left, int mid, int right) {

/*
	int i=0;
	int j=0;
	int k=0;
	int m = mid - left + 1;
	int r =  right - mid;
	

	char* temp1[m];
	char* temp2[r];
	
	for (i = 0; i < m; i++)
	{
		temp1[i] = list[left + i];
	}
	
	for (j = 0; j < r; j++)
	{
		temp2[j] = list[mid + 1+ j];
	}
	
	i = 0;
	j = 0;
	k = left;
	
	while (i < m && j < r)
	{
		if (strcmp(temp1[i], temp2[j]) <= 0 )
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
	
	while (i < m)
	{
		list[k] = temp1[i];
		i++;
		k++;
	}
	
	while (j < r)
	{
		list[k] = temp2[j];
	j++;
	k++;
	}*/int i=0;
	int j=0;
	int k=left;
	
	char* temp1[mid-left+1];
	char* temp2[right-mid];

	for (i = 0; i < mid-left+1; i++)
	{
		temp1[i] = list[left + i];
	}
	
	for (j = 0; j < right-mid; j++)
	{
		temp2[j] = list[mid + 1+ j];
	}
	
	i = 0;
	j = 0;

	while (i < mid-left+1 && j < right-mid)
	{
		if (strcmp(temp1[i], temp2[j]) <= 0 )
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
	
	while (j < right-mid)
	{
		list[k] = temp2[j];
		j++;
		k++;
	}
}


