#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void DFS(int n,int G[n+1][n+1]);
void dfs(int v,int n,int G[n+1][n+1]);
void print(int n,int G[n+1][n+1]);
double time_elapsed(struct timespec start,struct timespec end);

int* mark;

int main()
{
	int ncases;
	struct timespec start,end;
	scanf("%d",&ncases);
	
	while(ncases--)
	{
		int n;
		scanf("%d",&n);
		int G[n+1][n+1];
		
		mark = (int*)calloc((n+1),sizeof(int));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&G[i][j]);
	//	clock_gettime(CLOCK_REALTIME,&start);
		DFS(n,G);
	//	clock_gettime(CLOCK_REALTIME,&end);
	//	printf("time:%lf",time_elapsed(start,end));
	}
	
	return 0;
}

void print(int n,int G[n+1][n+1])
{
	for(int i=1;i<=n;i++)
	{
			for(int j=1;j<=n;j++)
			{
				printf("%d ",G[i][j]);
			}
			printf("\n");
	}
}



void DFS(int n,int G[n+1][n+1])
{
	int num_of_comp=0;
	
	for(int i=1;i<=n;i++)
	{
		if(mark[i] == 0)
		{
			mark[i]=1;
			dfs(i,n,G);
			num_of_comp++;
		}
	}
	
	printf("%d\n",num_of_comp);
}



void dfs(int v,int n,int G[n+1][n+1])
{
	for(int i=1;i<=n;i++)
	{
		if(G[v][i]==1 && mark[i]==0)
		{
			mark[i]=1;			
			dfs(i,n,G);
			
		}
	}
}
/*		
double time_elapsed(struct timespec start,struct timespec end)
{
	double time=(end.tv_sec - start.tv_sec)*1000000;
	time+=(end.tv_nsec - start.tv_nsec)*0.001;
	return time;
}*/
	

