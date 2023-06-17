#include <bits/stdc++.h> 

/* recursion
int f(int index, int w, vector<int> &profit, vector<int> &weight)
{
    if(index==0)
    {
       int q=(w/weight[index])*profit[index];
     return q;
    }

    int notTake=0+ f(index-1,w,profit,weight);

    int take=0;
    if(weight[index]<=w)
    {
        take=profit[index]+f(index,w-weight[index],profit,weight);
    }
    return max(notTake,take);

      

}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    
   return f(n-1,w,profit,weight);
}
*/

/* memoization

int f(int index, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp)
{
    if(index==0)
    {
       int q=(w/weight[index])*profit[index];
     return q;
    }
    if(dp[index][w]!=-1) return dp[index][w];

    int notTake=0+ f(index-1,w,profit,weight,dp);

    int take=0;
    if(weight[index]<=w)
    {
        take=profit[index]+f(index,w-weight[index],profit,weight,dp);
    }
    return dp[index][w]=max(notTake,take);

      

}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    
   return f(n-1,w,profit,weight,dp);
}

*/

// tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int j=0;j<=w;j++)
    {
        int q=j/weight[0];
        dp[0][j]=q*profit[0];

    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            int notTake=dp[i-1][j];
            int take=0;
            if(weight[i]<=j)
            {
                take=profit[i]+dp[i][j-weight[i]];
            }
            dp[i][j]=max(take,notTake);
        }
    }
   return dp[n-1][w];
}



