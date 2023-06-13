#include <bits/stdc++.h> 

/* not space optiized TC-> O(N*M)  SC-> O(N*M)
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    int dp[n][m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) dp[i][j]=grid[i][j];
            else {
                int down=INT_MAX;
                int right=INT_MAX;
                if(i>0) down= dp[i-1][j];
                if(j>0) right=dp[i][j-1];

                dp[i][j]=grid[i][j]+min(down,right);
            }

        }
    }
    return dp[n-1][m-1];
}
*/
// space optimized SC-> O(m)
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0);
    
    for(int i=0;i<n;i++)
    {
        vector<int> curr(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) curr[j]=grid[i][j];
            else {
                int down=INT_MAX;
                int right=INT_MAX;
                if(i>0) down= prev[j];
                if(j>0) right=curr[j-1];

                curr[j]=grid[i][j]+min(down,right);
            }

        }
        prev=curr;
    }
    return prev[m-1];
}

