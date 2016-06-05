#include <stdio.h>
#include "tme.h"
void select(int[],int);
void swap(int*,int*);
int main()
{
	 struct timespec start , end;
    clock_gettime(CLOCK_REALTIME,&start);
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++)
		scanf("%d",&arr[i]);
	select(arr,size);
	//printf("sorted array:\n");
	for(int i=0;i<size;i++)
		printf("%d\n",arr[i]);
	clock_gettime(CLOCK_REALTIME,&end);
    printf("Execution time: %.3lf microsec.\n", time_elapsed(start, end)); 
    return 0; 
}
void select(int a[],int size)
{
	for (int i=0;i<=size-2;i++)
	{
		//int min=i;
		for(int j=0;j<=size-2-i;j++)
		{
			if(a[j+1]<a[j])
					swap(&a[j],&a[j+1]);		
		}
		
	}
	
}
void swap(int *a,int *b)
{
		int temp=*a;
	*a=*b;
	*b=temp;
	
}
