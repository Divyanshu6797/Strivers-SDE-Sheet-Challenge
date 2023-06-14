#include <bits/stdc++.h> 
/*
memoization
int f(int ind,int T,vector<int>&nums,vector<vector<int>> &dp)
{

    if(ind==0)
    {
        if(T%nums[0]==0) 
        return T/nums[0];
        else
        return 1e9;
    }
    if(T==0)
    {
        return 0;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int notTake=0+f(ind-1,T,nums,dp);
    int take=INT_MAX;
    if(nums[ind]<=T) 
    take=1+f(ind,T-nums[ind],nums,dp);

    return dp[ind][T]=min(notTake,take);

}


int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans=f(n-1,x,num,dp);

    if(ans>=1e9)
    return -1;
    else return ans;
    
}
*/

// tabulation

int f(int ind,int T,vector<int>&nums,vector<vector<int>> &dp)
{

    if(ind==0)
    {
        if(T%nums[0]==0) 
        return T/nums[0];
        else
        return 1e9;
    }
    if(T==0)
    {
        return 0;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
   

}


int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));

   for(int i=0;i<=x;i++)
   {
       if(i%num[0]==0)
       dp[0][i]=i/num[0];

       else
       dp[0][i]=1e9;
   }
   for(int ind=1;ind<n;ind++)
   {
       for(int T=0;T<=x;T++)
       {
            int notTake=0+dp[ind-1][T];
    int take=INT_MAX;
    if(num[ind]<=T) 
    take=1+dp[ind][T-num[ind]];

    dp[ind][T]=min(notTake,take);

       }

   }
   
   int ans=dp[n-1][x];
   if(ans>=1e9)
   return -1;
   else 
   return ans;
    
}
