#include <stdio.h>
#include <time.h>
#include <string.h>
char a[10000];
char b[100];
int search(char *a,char *q);
int main()
{
	#define nano 1000000000L;
	double time;
	struct timespec start,stop;
	int k;
	clock_gettime(CLOCK_REALTIME, &start);
	scanf("%d\n", &k);
	while(k>0)
	{
		scanf(" %[^\n]", a);
		scanf(" %[^\n]", b);
		printf("%d\n",search(a,b));
		k--;
	}
	clock_gettime(CLOCK_REALTIME, &stop);
	time = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec)/nano;
	printf("Execution time: %f millisec\n", time);
	return 0;
}

int search(char *a,char *b)
{
	int n = strlen(a);
	int m = strlen(b);
	int i;
	for(i=0;i<n-m+1;i++)
	{
		int j = 0;
		while(j<m && b[j] == a[i+j]) 
		{
			j++;
		}
		if(j == m)
		return i;
	}
	return -1;
}
		


