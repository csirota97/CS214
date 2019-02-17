#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void merge(char**,int ,int ,int ,int );
void mergeSort(char**,int,int);

//void mergeLists(char** , int, int, int); 



void mergeSort(char** list,int left,int right)
{
    int mid;
        
    if(left<right)
    {
        mid=(left+right)/2;
        mergeSort(list,left,mid);        //left recursion
        mergeSort(list,mid+1,right);    //right recursion
        merge(list,left,mid,mid+1,right);    //merging of two sorted sub-arrays
    }
}
 
void merge(char** a,int i1,int j1,int i2,int j2)
{
    char** temp;    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(strcmp(a[i],a[j])<1)
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}



/*

void mergeSort(char** list, int left, int right){

	if (left==right) {
		return;
	}
//	printf("mergesort-----\n");

	int mid = (left+right)/2;
	mergeSort(list,left, mid);
//	printf("left\n");

	mergeSort(list,mid+1, right);
//	printf("right\n");

	mergeLists(list, left, mid, right);

}

void mergeLists(char** list, int left, int mid, int right) {
	char* newList[right-left];
	int l = left;
	int m = mid+1;
	int i = 0;

	int k;

	//delete this loop
	for (k=left; k<right-left ;k++){
		printf("%s\n",list[k]);
	}//delete

	while (l < mid && m < right) {
		printf("COMPARE:\n\t\t%s\n\t\t%s\n",list[l],list[m]);
		if (strcmp(list[l],list[m])<0) {
			newList[i]=list[l];
//			printf("WINNER:\n\t\t%s\n______________\n",list[l]);
			l++;i++;	
		}
		else if (strcmp(list[l],list[m])>=0) {
			newList[i]=list[m];
//			printf("WINNER:\n\t\t%s\t\t______________\n",list[m], newList[i]);
			m++;i++;
		}

		for (k=0; k<i;k++){
			printf("%s\n",newList[k]);
		}
	}
	printf("merge----\n");

	if (l <= mid) {
		while (l <= mid) {
			newList[i]=list[l];
			l++; i++;
		}
	}
	if (m <= right) {
		while (m <= right) {
			newList[i]=list[m];
			m++;i++;
		}
	}

//delete until next comment
int size =8;

	printf("---------------------\n");
	for (k=0; k<size ;k++){
		printf("%s\n",list[k]);
	}

	printf("---------------------\n");
//here
	for ( k=left; k<right;k++) {
		list[k]=newList[k-left];
	}

}


*/

int main(int argc, char* argv) {
//	char* input[] = {"This", "Is", "A", "Test", "Array", "For", "My", "MergeSort"};
	char* input[] = {"This", "Butt", "Duba", "Toes", "Sits", "Shit", "Pits", "Fits"};
	int size = 8;

	mergeSort(input, 0, size-1);

	for (; size>0;size--){
		printf("%s\n",input[8-size]);
	}

	return 0;
}
