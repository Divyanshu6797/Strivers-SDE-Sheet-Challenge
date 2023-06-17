#include <bits/stdc++.h> 


// subset sum
int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    
 for (int j = 0; j <= sum; j++) {
        if(j == 0 and arr[0] == 0)
            dp[0][j] = 2;
        else if(j == 0 || arr[0] == j)
            dp[0][j] = 1;
        else 
            dp[0][j] = 0;
    }
        


    
    

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            int notTake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j)
            {
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j]=take + notTake;


        }
    }
    int count=0;
   
    

    int s=(sum-target)/2;

    if((sum-target)%2!=0) return 0;

    for(int j=0;j<=sum;j++)
    {
        if(dp[n-1][j]>=0)
        {
            if(j==s)
            count+=dp[n-1][j];
        }
    }
    return count;

}
