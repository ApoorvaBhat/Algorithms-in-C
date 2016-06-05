#include <stdio.h>
#include <time.h>
int n;
struct student
{
	char usn[10];
	char name[20];
	int perc;
};
void distributionCount(struct student *, int, int, int, struct student *);
double time_elapsed(struct timespec, struct timespec);
int main()
{
	int l, u;
	struct timespec	start, end;
	clock_gettime(CLOCK_REALTIME, &start);
	scanf("%d\n",&n);
	struct student a[n],b[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%s %s %d\n",a[i].usn,a[i].name,&a[i].perc);
	}
	l=a[0].perc;
	u=a[0].perc;
	for(int i=0;i<n;i++)
	{
		if(a[i].perc<l)
		{
			l=a[i].perc;
		}
		if(a[i].perc>u)
		{
			u=a[i].perc;
		}
	}
	distributionCount(a,l,u,n,b);
	for(int i=n-1;i>=0;i--)
	{
		printf("%s %s %d\n",b[i].usn, b[i].name, b[i].perc);
	}
	clock_gettime(CLOCK_REALTIME, &end);
	printf("Execution time : %.6lf millisec.\n", time_elapsed(start, end));
	return 0;
}
void distributionCount(struct student *a, int l, int u, int n, struct student *b)
{
	int i,j;
	int d[u-l+1];
	for(j=0;j<=u-l;j++)
	{
		d[j]=0;
	}
	for(i=0;i<n;i++)
	{
		d[a[i].perc-l]=d[a[i].perc-l]+1;
	}
	for(j=1;j<=u-l;j++)
	{
		d[j]=d[j-1]+d[j];
	}
	for(i=n-1;i>=0;i--)
	{
		j=a[i].perc-l;
		b[d[j]-1]=a[i];
		d[j]=d[j]-1;
	}
}
double time_elapsed(struct timespec start, struct timespec end) 
{
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000; //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.0001; //add diff of tv_nsec too
	return t;
}
       

