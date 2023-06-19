#include <bits/stdc++.h> 
/* recursion
int f(int index,int buy,int fee,vector<int> &prices,int n)
{
    if(index==n)
    return 0;
   int profit;
    if(buy)
    {
        profit=max(f(index+1,1,fee,prices,n),-prices[index]+f(index+1,0,fee,prices,n));

    }
    else
    {
        profit=max(f(index+1,0,fee,prices,n),+prices[index]-fee+f(index+1,1,fee,prices,n));
    }
    return profit;
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    
    return f(0,1,fee,prices,n);
    
}

*/

/* memoization

int f(int index,int buy,int fee,vector<int> &prices,int n,vector<vector<int>> &dp)
{
    if(index==n)
    return 0;

    if(dp[index][buy]!=-1)  return dp[index][buy];
    
       int profit;
    if(buy)
    {
        profit=max(f(index+1,1,fee,prices,n,dp),-prices[index]+f(index+1,0,fee,prices,n,dp));

    }
    else
    {
        profit=max(f(index+1,0,fee,prices,n,dp),+prices[index]-fee+f(index+1,1,fee,prices,n,dp));
    }
    return dp[index][buy]=profit;
}
int maximumProfit(int n, int fee, vector<int> &prices) {

    vector<vector<int>> dp(n,vector<int>(2,-1));
    
    return f(0,1,fee,prices,n,dp);
    
}
*/

/* tabulation

int maximumProfit(int n, int fee, vector<int> &prices) {

    vector<vector<int>> dp(n+1,vector<int>(2,0));

    dp[n][0]=dp[n][0]=0;     // declaration of base cases is point less as its already 0

    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<=1;buy++)
        {
             int profit;
    if(buy)
    {
        profit=max(dp[index+1][1],-prices[index]+dp[index+1][0]);

    }
    else
    {
        profit=max(dp[index+1][0],+prices[index]-fee+dp[index+1][1]);
    }
        dp[index][buy]=profit;

        }
    }
    return dp[0][1];

}

*/

// tabulation + space 

int maximumProfit(int n, int fee, vector<int> &prices) {

    vector<int> after(2,0);
    vector<int> curr(2,0);

        // declaration of base cases is point less as its already 0

    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<=1;buy++)
        {
             int profit;
    if(buy)
    {
        profit=max(after[1],-prices[index]-fee+after[0]);

    }
    else
    {
        profit=max(after[0],+prices[index]+after[1]);
    }
        curr[buy]=profit;

        }
        after=curr;
    }
    return after[1];

}

    
    
