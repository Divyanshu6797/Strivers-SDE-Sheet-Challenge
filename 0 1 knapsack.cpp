#include <bits/stdc++.h> 

/*
int f(int index,vector<int> weight, vector<int> value, int maxweight)
{
	if(index==0)
	{
		if(weight[0]<=maxweight)
		return value[index];

		else
		 return 0;
	}
	if(maxweight==0)
	{
		return 0;
	}

		int take=INT_MIN;

        if (weight[index ]<= maxweight)
		 {
          take = value[index]+ f(index - 1, weight, value,  maxweight - weight[index]);
        }
        int nottake=f(index - 1, weight, value,  maxweight);
        

		return max(take,nottake);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n-1,weight,value,maxWeight);
}
*/

/*
memoization
int f(int index,vector<int> weight, vector<int> value, int maxweight,vector<vector<int>>&dp)
{
	if(index==0)
	{
		if(weight[0]<=maxweight)
		return value[index];

		else
		 return 0;
	}
	if(maxweight==0)
	{
		return 0;
	}
	if(dp[index][maxweight]!=-1)  return dp[index][maxweight];

		int take=INT_MIN;

        if (weight[index ]<= maxweight)
		 {
          take = value[index]+ f(index - 1, weight, value,  maxweight - weight[index],dp);
        }
        int nottake=f(index - 1, weight, value,  maxweight,dp);
        

		return dp[index][maxweight]=max(take,nottake);

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{ 
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,weight,value,maxWeight,dp);
}

*/

// tabulation

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{ 
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));

	
		for(int W=weight[0];W<=maxWeight;W++)
		 dp[0][W]=value[0];
	
	for(int index=1;index<n;index++)
	{
		for(int w=0;w<=maxWeight;w++)
		{
			int nottake=0+dp[index-1][w];
			int take=0;
			if(w>=weight[index])
			{
				take=value[index]+dp[index-1][w-weight[index]];
			}
			dp[index][w]=max(take,nottake);
		}
	}
	return dp[n-1][maxWeight];

	
}

