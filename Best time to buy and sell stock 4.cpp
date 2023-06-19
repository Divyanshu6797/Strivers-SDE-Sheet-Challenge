#include <bits/stdc++.h>
/*  recursion
int f(int index, int tranNo, vector<int> &prices, int n, int k) {
    if(index==n || tranNo==2*k)
    return 0;

    int profit=0;
    if(tranNo%2==0)
    {
        profit=max(f(index+1,tranNo,prices,n,k),-prices[index]+f(index+1,tranNo+1,prices,n,k));
        return profit;

    }
    else{
         profit=max(f(index+1,tranNo,prices,n,k),+prices[index]+f(index+1,tranNo+1,prices,n,k));
        return profit;

    }
}
int maximumProfit(vector<int> &prices, int n, int k) {
  return f(0, 0, prices, n, k);
}

*/

/* memoization

int f(int index, int tranNo, vector<int> &prices, int n, int k,vector<vector<int>> &dp) {
    if(index==n || tranNo==2*k)
    return 0;

    if(dp[index][tranNo]!=-1)
    return dp[index][tranNo];

    int profit=0;
    if(tranNo%2==0)
    {
        profit=max(f(index+1,tranNo,prices,n,k,dp),-prices[index]+f(index+1,tranNo+1,prices,n,k,dp));
        return  dp[index][tranNo]=profit;

    }
    else{
         profit=max(f(index+1,tranNo,prices,n,k,dp),+prices[index]+f(index+1,tranNo+1,prices,n,k,dp));
        return dp[index][tranNo]=profit;

    }
}
int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
  return f(0, 0, prices, n, k,dp);
}

*/

//tabulation

int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    
    for(int j=0;j<=2*k;j++)         // no point writing base cases
    {
        dp[n][j]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][2*k]=0;
    }

    for(int index=n-1;index>=0;index--)
    {
        for(int tranNo=2*k-1;tranNo>=0;tranNo--)
        {

             int profit=0;
             if (tranNo % 2 == 0) {
               profit = max(dp[index + 1][tranNo],
                            -prices[index] + dp[index + 1][tranNo + 1]);
               dp[index][tranNo] = profit;
             }

             else {
               profit = max(dp[index + 1][tranNo],
                            +prices[index] + dp[index + 1][tranNo + 1]);
               dp[index][tranNo] = profit;
             }
        }
    }

    return dp[0][0];
}
