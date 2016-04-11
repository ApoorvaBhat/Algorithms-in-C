//knapsack prob: 
//Given a set with n items and the knapsack's Capacity. Consider each item to //be i;each of which has weight wi and each having value vi. 
//We need to find the set whose combined weight is minimum & value to be minimum.
#include <stdio.h>
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   // Base Case
   if (n == 0 || W == 0)
       return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
 
   // Return the maximum of two cases: 
   // (1) nth item included 
   // (2) not included
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}
 

int main()
{
	int noitems;int wt[5];int val[5];
	scanf("%d",&noitems);
	for(int i = 0; i< noitems; i++)
	{
		
		 scanf("%d",&wt[i]);
	}
	for(int j = 0 ; j < noitems; j++)
	{
		
		 scanf("%d",&val[j]);
	}
	int W ;

	scanf("%d", &W);
	int n = sizeof(val)/sizeof(val[0]);// to get no. of elements in the array.

    
    printf("%d\n", knapSack(W, wt, val, n));
    return 0;
}