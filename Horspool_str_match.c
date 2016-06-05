#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void shiftTable(char* b);
int horspoolMatch(char*,int*,char*);
int table[200];
int main()
{
	int k =0;
	char a[1000];
	char b[10];
	scanf("%s",a);
	scanf("%s",b);
	k = horspoolMatch(b,table,a);
	printf("%d\n",k);
	return 0;
}

void shiftTable(char* b)
{
	int i =0,j =0;
	j = strlen(b);
	for(i=0;i<j;i++)
	{
		table[i] = j;
	}	
	for(i=0;i<j-1;i++)
	{
		table[b[i]] = j-1-i;
	}
}

int horspoolMatch(char *b,int *table,char *a)
{
	int i =0,j=0,k=0;
	shiftTable(b);
	j = strlen(b);
	i = strlen(b)-1;
	while(i<= strlen(a)-1)
	{
		k = 0;
		while(k<=j-1 && (b[j-1-k] == a[i-k]))
		{
			k++;
		}
		if(k == j)
		{
			return i-j+1;
		}
		else
		{
			i = i+table[a[i]];
		}
	}
	return -1;
}		
		
			
