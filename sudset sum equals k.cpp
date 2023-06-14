#include <bits/stdc++.h> 

/* Recursion TC-> O(2^n)  SC->O(N) stack space
bool f(int n,int target,vector<int>&arr)
{
    if(target==0)
    return true;

    if(n==0)
    {
        if(arr[n]==target)
        return true;
        else return false;
    }

    bool take;
    if(arr[n]>target) 
    {
      take = false;
    }
    else
    {
      take=f(n-1,target-arr[n],arr);
    }
    bool nottake= f(n-1,target,arr);

    if(take || nottake)
    return true;
    else
     return false;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
     return f(n - 1, k, arr);
      }
      */

      
      /* memoization
      
bool f(int n,int target,vector<int>&arr,vector<vector<int>> &dp)
{
    if(target==0)
    return true;

    if(n==0)
    {
        if(arr[n]==target)
        return true;
        else return false;
    }
    if(dp[n][target]!=-1) return dp[n][target];

    bool take;
    if(arr[n]>target) 
    {
      take = false;
    }
    else
    {
      take=f(n-1,target-arr[n],arr,dp);
    }
    bool nottake= f(n-1,target,arr,dp);

    return dp[n][target]= take| nottake;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n - 1, k, arr,dp);



      }
      */

      // tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if (arr[0] <=k) dp[0][arr[0]] = true;

    for(int ind=1;ind<n;ind++)  {
        for(int target=1;target<=k;target++) {
            bool notTake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take|notTake;

        }
    }
    return dp[n-1][k];

    
}
