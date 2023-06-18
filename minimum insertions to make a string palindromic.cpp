#include <bits/stdc++.h> 

// length of string - length of plaindromic subsequence
// length of plaindromic subsequence can be found by -> find lcs of string and reversed string
// extended indexing

int minInsertion(string &str)
{
    int n=str.size();
    string str1=str;
    string str2=str;
    reverse(str2.begin(),str2.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

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
            if(str1[i-1]==str2[j-1])         //extended indexing
            dp[i][j]=1+dp[i-1][j-1];

            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][n];


    
}
