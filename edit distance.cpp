#include<bits/stdc++.h>
using namespace std;
/* recursion  TC->exponential  SC-> stack space O(n+m)
int f(string str1,string str2,int i,int j)
{
    if(i<0)
    return j+1;

    if(j<0)
    return i+1;

    if(str1[i]==str2[j])
    return f(str1,str2,i-1,j-1);

    else 
    {
        int insertop=1+f(str1,str2,i-1,j);       // insert operation
        int deleteop=1+f(str1,str2,i,j-1);       // delete operation
        int replaceop=1+f(str1,str2,i-1,j-1);    // replace operation

        return min(min(insertop,deleteop),replaceop);
    }
    

}
int editDistance(string str1, string str2)
{
    int n=str1.size();
    int m=str2.size();

    return f(str2,str1,m-1,n-1);
    
}
*/

/* memoization

int f(string str1,string str2,int i,int j,vector<vector<int>> &dp)
{
    if(i<0)
    return j+1;

    if(j<0)
    return i+1;
    if(dp[i][j]!=-1)  return dp[i][j];

    if(str1[i]==str2[j])
    return dp[i][j]= f(str1,str2,i-1,j-1,dp);

    else 
    {
        int insertop=1+f(str1,str2,i-1,j,dp);       // insert operation
        int deleteop=1+f(str1,str2,i,j-1,dp);       // delete operation
        int replaceop=1+f(str1,str2,i-1,j-1,dp);    // replace operation

        return dp[i][j]=min(min(insertop,deleteop),replaceop);
    }
    

}
int editDistance(string str1, string str2)           // converting str2 to str1
{
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>> dp(m,vector<int>(n,-1));

    return f(str2,str1,m-1,n-1,dp);
    
}
*/

// tabulation

int editDistance(string str1, string str2)           // converting str2 to str1
{
    int n=str1.size();
    int m=str2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j] = 1+min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j]);
            }
        }
        return dp[n][m];

}



