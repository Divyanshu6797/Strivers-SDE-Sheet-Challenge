#include<bits/stdc++.h>
using namespace std;

/* recursion
int f(int index,int prev_index, int arr[],int n)
{
    if(index==n)       // base case
    return 0;

    int notTake= 0 + f(index+1,prev_index,arr,n);

    int take=0;
    if(prev_index==-1 || arr[index]>arr[prev_index])
    {
        take=1+f(index+1,index,arr,n);
    }
    return max(take,notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    return f(0,-1,arr,n);
}
*/

/* memoization   extend coordinates
int f(int index,int prev_index, int arr[],int n, vector<vector<int>> &dp)
{
    if(index==n)       // base case
    return 0;

    if(dp[index][prev_index+1]!=-1)  return  dp[index][prev_index+1];

    int notTake= 0 + f(index+1,prev_index,arr,n,dp);

    int take=0;
    if(prev_index==-1 || arr[index]>arr[prev_index])
    {
        take=1+f(index+1,index,arr,n,dp);
    }
    return dp[index][prev_index+1]=max(take,notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,dp);
}
*/

/* tabulation   extend coordinates

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    

    for(int index=n-1;index>=0;index--)
    {
        for(int prev_index=index-1;prev_index>=-1;prev_index--)
        {

            int notTake= 0 + dp[index+1][prev_index+1];

    int take=0;
    if(prev_index==-1 || arr[index]>arr[prev_index])
    {
        take=1+dp[index+1][index+1];
    }
    dp[index][prev_index+1]=max(take,notTake);

        }
    }
    return dp[0][0];
}

*/
/*  tabulation + space optimized    extend coordinates
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> after(n+1,0);
    vector<int> curr(n+1,0);

    

    for(int index=n-1;index>=0;index--)
    {
        for(int prev_index=index-1;prev_index>=-1;prev_index--)
        {

            int notTake= 0 + after[prev_index+1];

    int take=0;
    if(prev_index==-1 || arr[index]>arr[prev_index])
    {
        take=1+after[index+1];
    }
    curr[prev_index+1]=max(take,notTake);

        }
        after=curr;
    }

    return curr[0];
}

*/

// binary search

int longestIncreasingSubsequence(int arr[], int n)
{
   vector<int> temp;
   temp.push_back(arr[0]);

   for(int i=1;i<n;i++)
   {
       if(arr[i]>temp.back())
       {
           temp.push_back(arr[i]);

       }
       else
       {
           int ind=lower_bound(temp.begin(),temp.end() ,arr[i])-temp.begin();
           temp[ind]=arr[i];
       }
   }
   return temp.size();
}

