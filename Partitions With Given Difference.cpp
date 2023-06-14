#include <bits/stdc++.h> 
int mod=(int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    sort(arr.begin(),arr.end(),greater<int>());
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];

    }
    int tar=(sum-d);
    if(tar<0 || tar%2!=0) return 0;
    tar=tar/2;
    
    vector<vector<int>> dp(n,vector<int>(tar+1,0));

    if(arr[0]==0 ) dp[0][0]=2;
    else dp[0][0]=1;

    for(int i=0;i<n;i++)
    {
    
        dp[i][0]=1;
    }
        if(arr[0]<=tar && arr[0]!=0)
        {
            dp[0][arr[0]]=1;
        }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=tar;j++)
        {
            int up=dp[i-1][j];
            int upleft=0;
            if(arr[i]<=j)
            {
                upleft=dp[i-1][j-arr[i]];
            }
            dp[i][j]=(up+upleft)%mod;;


        }
    }
    return dp[n-1][tar];
    
}


