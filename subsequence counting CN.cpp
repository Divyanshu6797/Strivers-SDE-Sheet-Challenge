#include <bits/stdc++.h> 
int mod=(int)(1e9+7);
/* recursion 
int f(string t, string s, int i, int j)
{
    if(i<0)
    return 1;
    if(j<0)
    return 0;
     
     if(t[j]==s[i])
     return f(t,s,i-1,j-1)+f(t,s,i,j-1);
     else 
     return f(t,s,i,j-1);
    

}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    int i=s.size();
    int j=t.size();

    return f(t,s,i-1,j-1 );
} 
*/

/* memoization 

int f(string t, string s, int i, int j,vector<vector<int>> &dp)
{
    if(i<0)
    return 1;
    if(j<0)
    return 0;
    if(dp[j][i]!=-1) return dp[j][i]%mod;
     
     if(t[j]==s[i])
     return dp[j][i]=(f(t,s,i-1,j-1,dp)+f(t,s,i,j-1,dp))%mod;
     else 
     return dp[j][i]=f(t,s,i,j-1,dp)%mod;
    

}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    int i=s.size();
    int j=t.size();
    vector<vector<int>> dp(j,vector<int>(i,-1));

    return f(t,s,i-1,j-1 ,dp);
} 
*/

// tabulation
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    
    vector<vector<int>> dp(lt+1,vector<int>(ls+1,0));
     
     for(int i=0;i<=lt;i++)
     {
         dp[i][0]=1;
     }

     for(int i=1;i<=lt;i++)
     {
         for(int j=1;j<=ls;j++)
         {
             if(t[i-1]==s[j-1])
             {
                 dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
             }
             else
             dp[i][j]=dp[i-1][j]%mod;
         }
     }

    
     return dp[lt][ls];



    
} 
