#include <bits/stdc++.h> 
/* recursion
int f(int start,int end,string s)
{
    if(start==end)
    {
        return 1;
    }
    if(start>end)
    return 0;

    if(s[start]==s[end])
    {
        return 2+f(start+1,end-1,s);
    }
    else
    return max(f(start+1,end,s),f(start,end-1,s));
}
int longestPalindromeSubsequence(string s)
{
   int n=s.size();
   return f(0,n-1,s);
}

*/

/* memoization

int f(int start,int end,string s,vector<vector<int>> &dp)
{
    if(start==end)
    {
        return 1;
    }
    if(start>end)
    return 0;
    if(dp[start][end]!=-1) return dp[start][end];

    if(s[start]==s[end])
    {
        return dp[start][end]=2+f(start+1,end-1,s,dp);
    }
    else
    return dp[start][end]=max(f(start+1,end,s,dp),f(start,end-1,s,dp));
}
int longestPalindromeSubsequence(string s)
{
   int n=s.size();
   vector<vector<int>> dp(n,vector<int>(n,-1));
   return f(0,n-1,s,dp);
}
*/

// tabulation   LCS of string and reversed string is the answer

int longestPalindromeSubsequence(string s)
{
   int n=s.size();
   vector<vector<int>> dp(n+1,vector<int>(n+1,0));
   string s2=s;
   reverse(s2.begin(),s2.end());
   

   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=n;j++)
       {
           if(i==0 || j==0)
           dp[i][j]=0;
       }
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(s[i-1]==s2[j-1])
           {
               dp[i][j]=1+dp[i-1][j-1];
           }
           else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
       }
   }
   return dp[n][n];
}


