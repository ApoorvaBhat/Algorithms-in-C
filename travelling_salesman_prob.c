#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct 
{
	int symbol;
	int  dirn;
}node;

int min_wt = INT_MAX;
int number_of_nodes=0;

void change_dirn(node *p,int mob_ind);
void swap_nodes(node *a,node *b);
int GetLargestMobileindex(node *p);
void calculate_min_cost_Hckt(int weights[number_of_nodes][number_of_nodes],node *p,int *ckt_formed);
void compute_weight(int weights[number_of_nodes][number_of_nodes],node *p,int *ckt_formed);

int main()
{
	scanf("%d",&number_of_nodes);
	node *p=(node *) malloc((number_of_nodes)*sizeof(node));
	int weights[number_of_nodes][number_of_nodes];
	int ckt_formed[number_of_nodes];
	for(int i=0;i<number_of_nodes;i++)
	{
		p[i].symbol=i+1;
		p[i].dirn=0;
		
		for(int j=0;j<number_of_nodes;j++)
		{
			scanf("%d",&weights[i][j]);
		}
	}
	
	calculate_min_cost_Hckt(weights,p,ckt_formed);
	printf("Minimum Cost:%d\n",min_wt);
	printf("Hamilton Circuit formed:");
	for(int i=0;i<number_of_nodes;i++)
	{
		printf("%d ",ckt_formed[i]);
	}
		printf("%d\n",ckt_formed[0]);
}



void calculate_min_cost_Hckt(int weights[number_of_nodes][number_of_nodes],node *p,int *ckt_formed)
{
	compute_weight(weights,p,ckt_formed);
	int mobile_index=GetLargestMobileindex(p);
	int swap_index;
	while(mobile_index!=-1)
	{	
		swap_index = (p[mobile_index].dirn == 0) ? mobile_index - 1 : mobile_index + 1;
		swap_nodes(&p[mobile_index],&p[swap_index]);
		change_dirn(p,swap_index);
		compute_weight(weights,p,ckt_formed);
		mobile_index=GetLargestMobileindex(p);	
	}
}

void compute_weight(int weights[number_of_nodes][number_of_nodes],node *p,int *ckt_formed)
{
	int weight_of_perm=0;
	for(int i=0;i < number_of_nodes-1;i++)
	{
		weight_of_perm+=weights[p[i].symbol-1][p[i+1].symbol-1];
	}
	weight_of_perm+=weights[p[number_of_nodes-1].symbol-1][p[0].symbol-1];
	if(weight_of_perm < min_wt)
	{
		min_wt=weight_of_perm;
		for(int i=0;i<number_of_nodes;i++)
		{
			ckt_formed[i]=p[i].symbol;
		}
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

