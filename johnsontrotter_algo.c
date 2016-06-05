#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int symbol;
	int  dirn;
}node;

int number_of_nodes=0;

void johnson(node *p);
void change_dirn(node *p,int mob_ind);
void swap_nodes(node *a,node *b);
int GetLargestMobileindex(node *p);
void permutation_print(node *p);

int main()
{
	int test_case;
	scanf("%d",&test_case);
	while(test_case--)
	{
		scanf("%d",&number_of_nodes);
		node *p=(node *) malloc((number_of_nodes)*sizeof(node));
		for(int i=0;i<number_of_nodes;i++)
		{
			p[i].symbol=i+1;
			p[i].dirn=0;		
		}
		johnson(p);
		free(p);
	}
	
}

void johnson(node *p)
{
	int mobile_index=GetLargestMobileindex(p);
	int swap_index;
	int i=0;
	printf("%2d: ",++i);
	permutation_print(p);
	while(mobile_index!=-1)
	{	
		swap_index = (p[mobile_index].dirn == 0) ? mobile_index - 1 : mobile_index + 1;
		swap_nodes(&p[mobile_index],&p[swap_index]);
		change_dirn(p,swap_index);
		printf("%2d: ",++i);
		permutation_print(p);
		mobile_index=GetLargestMobileindex(p);	
	}
}


int GetLargestMobileindex(node *p)
{
	int m=-1;
    	for(int i=0;i< number_of_nodes;i++)
    	{
		if((p[i].dirn == 0) && (i > 0) && (p[i].symbol > p[i-1].symbol)) 
		{
		    if(m ==-1) m=i;
		    else if (p[i].symbol > p[m].symbol) m = i;
		}
		else if((p[i].dirn == 1) && (i < number_of_nodes-1) && (p[i].symbol > p[i+1].symbol))
		{
		    if(m == -1) m = i;
		    else if(p[i].symbol > p[m].symbol) m = i;
		}
        }
    	return m;
}

void swap_nodes(node *a,node *b)
{
	node temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void change_dirn(node *p,int mob_ind)
{
	for(int i=0;i<number_of_nodes;i++)
	{	
		if(p[i].symbol>p[mob_ind].symbol) p[i].dirn=1-p[i].dirn;

	}
}

void permutation_print(node *p)
{
	for(int i=0;i<number_of_nodes;i++)
	{
		printf("%c",(p[i].dirn == 0) ? '<':'>');
		printf("%d",p[i].symbol);	
	}
	printf("\n");

}
