#include<bits/stdc++.h>
using namespace std;
/* recursion 
bool f(int i,int j,string pattern,string text)
{
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;
   if(i>=0 && j<0)
   {
      for(int ii=0;ii<=i;ii++)
      {
         if(pattern[ii]!='*') return false;
      }
      return true;
   }

   if(pattern[i]==text[j] || pattern[i]=='?')
   return f(i-1,j-1,pattern,text);
   else if(pattern[i]=='*')
   {
      return f(i-1,j,pattern,text) | f(i,j-1,pattern,text);
   }
   else return false;

}
bool wildcardMatching(string pattern, string text)
{
   int n=pattern.size();
   int m=text.size();

   return f(n-1,m-1,pattern,text);
}
*/

/* memoization

bool f(int i,int j,string pattern,string text,vector<vector<int>> &dp)
{
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;
   if(i>=0 && j<0)
   {
      for(int ii=0;ii<=i;ii++)
      {
         if(pattern[ii]!='*') return false;
      }
      return true;
   }
   if(dp[i][j]!=-1)  return dp[i][j];


   if(pattern[i]==text[j] || pattern[i]=='?')
   return dp[i][j]=f(i-1,j-1,pattern,text,dp);
   else if(pattern[i]=='*')
   {
      return  dp[i][j]=f(i-1,j,pattern,text,dp) | f(i,j-1,pattern,text,dp);
   }
   else 
   return  dp[i][j]=false;

}
bool wildcardMatching(string pattern, string text)
{
   int n=pattern.size();
   int m=text.size();
   vector<vector<int>> dp(n,vector<int>(m,-1));

   return f(n-1,m-1,pattern,text,dp);
}
*/

bool wildcardMatching(string pattern, string text)
{
   int n=pattern.size();
   int m=text.size();
   vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
     dp[0][0]=true;

     for(int j=1;j<=m;j++)
     {
        dp[0][j]=false;
     }
     for(int i=1;i<=n;i++)
     {
     bool flag=true;
     
        for(int ii=1;ii<=i;ii++)
        {
           if(pattern[ii-1]!='*') flag=false;
        }
        dp[i][0]=flag;
     }
     

     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
           if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')
           dp[i][j]=dp[i-1][j-1];

           else if(pattern[i-1]=='*')
          {
             dp[i][j]=dp[i-1][j] | dp[i][j-1];
          }
           else 
             dp[i][j]=false;


        }
     }
     return dp[n][m];

     
}



