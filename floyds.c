#include<stdio.h>
#include<stdlib.h>
int** floyds(int**,int);
int main()
{
	int n,i,j;
	int ** reach;
	scanf("%d",&n);
	int** ip=(int**)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		ip[i]=(int*)malloc(sizeof(int)*n);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&ip[i][j]);
		}
	}
	reach=floyds(ip,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",reach[i][j]);
		}
		printf("\n");
	}
}
int** floyds(int** ip,int n)
{
	int min(int,int);
	int i,k,j;
	int** reach=(int**)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		reach[i]=(int*)malloc(sizeof(int)*n);
	}
	 for (i = 0; i < n; i++)
	 {
        for (j = 0; j < n; j++)
		{
            reach[i][j] = ip[i][j];
		}
	 }
	 for (k = 0; k < n; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < n; j++)
            {
                // If vertex k is on a path from i to j,
                // then make sure that the value of reach[i][j] is 1
                reach[i][j] = min(reach[i][j],(reach[i][k] +reach[k][j]));
            }
        }
    }
	return reach;
}
int min(int a ,int b)
{
	return a<b?a:b;
}