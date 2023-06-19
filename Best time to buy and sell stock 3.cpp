#include <bits/stdc++.h> 

/* recursion 
int f(int index,int buy,int cap,vector<int> prices,int n)
{
    if(index==n || cap==0)
    return 0;

int profit;
    if(buy)
    {
        profit=max(f(index+1,1,cap,prices,n),-prices[index]+f(index+1,0,cap,prices,n));
        return profit;

    }
    else
    {
        profit=max(f(index+1,0,cap,prices,n),+prices[index]+f(index+1,1,cap-1,prices,n));
        return profit;
    }
}
int maxProfit(vector<int>& prices, int n)
{
    return f(0,1,2,prices,n);
}

*/

/* memoization

int f(int index,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp)
{
    if(index==n || cap==0)
    return 0;

    if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];

int profit;
    if(buy)
    {
        profit=max(f(index+1,1,cap,prices,n,dp),-prices[index]+f(index+1,0,cap,prices,n,dp));
        return dp[index][buy][cap]=profit;

    }
    else
    {
        profit=max(f(index+1,0,cap,prices,n,dp),+prices[index]+f(index+1,1,cap-1,prices,n,dp));
        return dp[index][buy][cap]=profit;
    }
}
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,2,prices,n,dp);
}
*/

// tabulation

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
 
     for(int i=0;i<=n;i++)                    // no point writing base case as all cells are already 0
     {
         for(int j=0;j<2;j++)
         {
             for(int k=0;k<3;k++)
             {
                 if(i==n || k==0)
                 dp[i][j][k]=0;
             }
         }
     }
     for(int index=n-1;index>=0;index--)                    // no point writing base case as all cells are already 0
     {
         for(int buy=0;buy<2;buy++)
         {
             for(int cap=1;cap<3;cap++)
             {
                 int profit;
                  if(buy)
                  {
                    profit=max(dp[index+1][1][cap],-prices[index]+dp[index+1][0][cap]);
                    dp[index][buy][cap]=profit;

                     }
                      else
                          {
                      profit=max(dp[index+1][0][cap],+prices[index]+dp[index+1][1][cap-1]);
                      dp[index][buy][cap]=profit;
                     }
                
             }
         }
     }
     return dp[0][1][2];
   

}


