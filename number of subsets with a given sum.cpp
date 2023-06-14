#include <bits/stdc++.h> 

/* recursion
int f(int index,int target,vector<int>&arr)
{
    if(target==0)  return 1;
    if(index==0)
    {
        if(arr[index]==target) return 1;
        else return 0;
    }

    int notTake=f(index-1,target,arr);
    int take=0;
    if(arr[index]<=target)
    {
        take=f(index-1,target-arr[index],arr);
    }
    return take+notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    return f(n-1,tar,num);
}
*/

/* memoization not working for all test cases
int f(int index,int target,vector<int>&arr,vector<vector<int>> &dp)
{
    if(target==0)  return 1;
    if(index==0)  return arr[0]==target;
    
    if(dp[index][target]!=-1) return dp[index][target];

    int notTake=f(index-1,target,arr,dp);
    int take=0;
    if(arr[index]<=target)
    {
        take=f(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]=take+notTake;
}
int findWays(vector<int> &num, int tar)
{
    

    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
}
*/
// tabulation
int findWays(vector<int> &num, int tar)
{
    sort(num.begin(),num.end(),greater<int>());
    
    
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));

    if(num[0]==0 ) dp[0][0]=2;
    else dp[0][0]=1;

    for(int i=0;i<n;i++)
    {
    
        dp[i][0]=1;
    }
        if(num[0]<=tar && num[0]!=0)
        {
            dp[0][num[0]]=1;
        }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=tar;j++)
        {
            int up=dp[i-1][j];
            int upleft=0;
            if(num[i]<=j)
            {
                upleft=dp[i-1][j-num[i]];
            }
            dp[i][j]=up+upleft;


        }
    }
    return dp[n-1][tar];
    
}


