#include<bits/stdc++.h>
/* recursion gives TLE
long f(int *denominations,int index,int value)
{
    if(index==0)
    {
        if(value%denominations[index]%2==0)
        {
            return 1;
        }
        else return 0;
    }
    if(value==0)
    {
        return 1;
    }
    long notTake=f(denominations,index-1,value);
    long take=0;

    if (denominations[index] <= value) {

    take = f(denominations, index, value - denominations[index]);

    }
    return take+notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    return f(denominations,n-1,value);
}
*/
/* memoization
long f(int *denominations,int index,int value,vector<vector<long>> &dp)
{
    if(index==0)
    {
        if(value%denominations[index]==0)
        {
            return 1;
        }
        else return 0;
    }
    if(value==0)
    {
        return 1;
    }
    if(dp[index][value]!=-1)  return dp[index][value];

    long notTake=f(denominations,index-1,value,dp);
    long take=0;

    if (denominations[index] <= value) {

    take = f(denominations, index, value - denominations[index],dp);

    }
    return dp[index][value]=take+notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(denominations,n-1,value,dp);
}
*/

// tabulation
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,0));

    for(int j=0;j<=value;j++)
    {
         
         dp[0][j]=(j%denominations[0]==0);

         
    }
   
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=value;j++)
        {
            long notTake=dp[i-1][j];

            long take=0;

            if(denominations[i]<=j)
            {
                take=dp[i][j-denominations[i]];
            }
            dp[i][j]=take+notTake;
        }
    }
    return dp[n-1][value];
   
}

