#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int test_cases;
typedef struct node{
	char name[20];
	char reg[10];
	float cgpa;

}student;

typedef struct pair{
	float val;
	int count;
}pair;
void sort(student* array,int size);
double diff(struct timespec* s,struct timespec* e);

int main()
{
	int i;
	struct timespec s,e;
	scanf("%d",&test_cases);
	student array[test_cases+1];
	for(i = 0;i < test_cases;i++)
	{
		student temp;
		scanf("%s",&temp.reg);
		scanf("%s",&temp.name);
		scanf("%f",&temp.cgpa);
		array[i] = temp;	
	}
	clock_gettime(CLOCK_REALTIME,&s);
	//sort(array,test_cases+1);
	clock_gettime(CLOCK_REALTIME,&e);
	
	for(i = 0;i < test_cases;i++)
	{
		printf("%s ",array[i].reg);
		printf("%s ",array[i].name);
		printf("%f ",array[i].cgpa);	
		printf("\n");
	}
	
	printf("\n%f milliseconds\n",diff(&s,&e));
	return 0;
}

void sort(student* array,int size)
{
	int min = 150;
	int max = 0;
	int i;
	for(i = 0;i < test_cases;i++)
	{
		if(array[i].cgpa < min)
			min = array[i].cgpa;
		if(array[i].cgpa >max)
			max = array[i].cgpa;
		
		pair frequeny[max-min+1];
		
		for(i = 0;i < (max-min+1);i++)
		{
			pair temp;
			temp.val = min+i;	
		}		
	}
}

double diff(struct timespec* s,struct timespec* e)
{
  double temp;
  temp = (e->tv_sec - s->tv_sec)*1000;
  temp = temp + (e->tv_nsec - s->tv_nsec)*0.000001;
  return temp;
}
