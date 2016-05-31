#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
typedef struct 
{
	char regno[11];
	char name[21];
	double cgpa;
}student;

void initialise_records(student s[],int n);
void print_records(student s[],int n);
void quick_sort(student s[],int, int);
int partition(student A[],int l, int r);
void swap(student *a, student *b);
double time_elapsed(struct timespec start,struct timespec end);



int main()
{	
	int n;
	struct timespec start,end;
	scanf("%d",&n);
	student s[n];	
	initialise_records(s,n);
	clock_gettime(CLOCK_REALTIME,&start);		
	quick_sort(s,0,(n-1));
	clock_gettime(CLOCK_REALTIME,&end);
	print_records(s,n);
	printf("Time elapsed:%lf microseconds",time_elapsed(start,end));
	return 0;
}

void initialise_records(student s[],int n)
{
	for(int i=0;i<n;i++)
		scanf("%s %s %lf",s[i].regno,s[i].name,&s[i].cgpa);
		
		
}
void print_records(student s[],int n)
{

	for(int i=0;i<n;i++)
		printf("%s%s%.2lf\n",s[i].regno,s[i].name,s[i].cgpa);
}

void quick_sort(student A[],int l, int r)
{

	if(l < r)
	{
		
		int s = partition(A,l,r);
		quick_sort(A,l,(s-1));
		quick_sort(A,(s+1),r);
	}		
}

int partition(student A[],int l, int r)
{
	student p = A[l];
	int i=l;
	int j=r+1;
	

	do
	{
		do
		{	
			i=i+1;
		}
		while(strcmp(A[i].regno,p.regno) < 0);
		
		do
		{
				j=j-1;
				
		}
		while(strcmp(A[j].regno,p.regno) > 0);

		swap(&A[i],&A[j]);
		
		
	}while(i < j);
	
	swap(&A[i],&A[j]);
	swap(&A[l],&A[j]);
	
	return j;
}


void swap(student *a, student *b) 
{
	student temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

double time_elapsed(struct timespec start,struct timespec end)
{
	double time=(end.tv_sec - start.tv_sec)*1000000;
	time+=(end.tv_nsec - start.tv_nsec)*0.001;
	return time;
}
