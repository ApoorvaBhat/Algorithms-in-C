#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node{
	char name[20];
	char reg[10];
	float cgpa;

}student;


void heapsort(student* array,int size);
void heapbottomup(student* array,int size);
void maxkeydelete(student* array,int size);
void heapify(student* array,int size,int key);
void swap(student* a,student* b);
double diff(struct timespec* s,struct timespec* e);

int main()
{
	int test_cases,i;
	struct timespec s,e;
	scanf("%d",&test_cases);
	student array[test_cases+1];
	for(i = 1;i <= test_cases;i++)
	{
		student temp;
		scanf("%s",&temp.reg);
		scanf("%s",&temp.name);
		scanf("%f",&temp.cgpa);
		array[i] = temp;	
	}
	clock_gettime(CLOCK_REALTIME,&s);
	heapsort(array,test_cases+1);
	clock_gettime(CLOCK_REALTIME,&e);
	
	for(i = 1;i <= test_cases;i++)
	{
		printf("%s ",array[i].reg);
		printf("%s ",array[i].name);
		printf("%f ",array[i].cgpa);	
		printf("\n");
	}
	
	printf("\n%f milliseconds\n",diff(&s,&e));
	return 0;
}

void heapsort(student* array,int size)
{
	heapbottomup(array,size);
	int i ;
	for(i = size;i > 1;i--)
	{
		maxkeydelete(array,i);
	}
}

void heapbottomup(student* array,int size)
{
	if(size <= 1)
		return;
	int i;
	for(i = size/2;i >= 1;i--)
		heapify(array,size,i);	
}

void maxkeydelete(student* array,int size)
{
	swap(&array[1],&array[size]);
	heapify(array,size - 1,1);
}

void heapify(student* array,int size,int key)
{
	if(2*key > size)
		return;
	int j = 2*key;
	if(j+1 <= size)
		if(strcmp(array[j+1].reg,array[j].reg) > 0)	
			j = j + 1;
	if(strcmp(array[j].reg,array[key].reg) > 0)
	{
		swap(&array[j],&array[key]);
		heapify(array,size,j);		
	}
}

void swap(student* a,student* b)
{
	student temp = *a;
	*a = *b;
	*b = temp;  
}


double diff(struct timespec* s,struct timespec* e)
{
  double temp;
  temp = (e->tv_sec - s->tv_sec)*1000;
  temp = temp + (e->tv_nsec - s->tv_nsec)*0.000001;
  return temp;
}
