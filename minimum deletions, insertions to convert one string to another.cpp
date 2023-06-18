#include <bits/stdc++.h> 

// extended indexing
// n1+n2- 2*lcs is the answer      think
int canYouMake(string &str, string &ptr)
{
    int n1=str.size();
    int n2=ptr.size();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }

    }

     for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(str[i-1]==ptr[j-1])   // extended indexing
             dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    }
    return n1+n2-(2*dp[n1][n2]);

}
