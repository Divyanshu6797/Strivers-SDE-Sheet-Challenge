#include<bits/stdc++.h>
using namespace std;
/* recursion 
long f(long index,long n,int buy,long *values)
{
    if(index==n)
    return 0;

    if(buy)
    {
        return max(f(index+1,n,1,values),-values[index]+f(index+1,n,0,values));  // buy or not buy
    }
    else
    return max(f(index+1,n,0,values),+values[index]+f(index+1,n,1,values));  // sell or not sell
}
long getMaximumProfit(long *values, int n)
{

    return f(0,n,1,values);

    
}
*/


/* memoization
long f(long index,long n,int buy,long *values,vector<vector<long>> &dp)
{
    if(index==n)
    return 0;
    if(dp[index][buy]!=-1)  return dp[index][buy];

    if(buy)
    {
        return dp[index][buy]=max(f(index+1,n,1,values,dp),-values[index]+f(index+1,n,0,values,dp));  // buy or not buy
    }
    else
    return dp[index][buy]=max(f(index+1,n,0,values,dp),+values[index]+f(index+1,n,1,values,dp));  // sell or not sell
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n,vector<long>(2,-1));
    return f(0,n,1,values,dp);

    
}

*/

//tabulation

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,0));

   
    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<2;buy++)
        {
            long profit=0;
            if (buy) {
              profit = max(dp[index + 1][1],
                           -values[index] + dp[index + 1][0]); // buy or not buy
            } else
              profit =
                  max(dp[index + 1][0],
                      +values[index] + dp[index + 1][1]); // sell or not cell

            dp[index][buy] = profit;
        }
    }
    return dp[0][1];

}
