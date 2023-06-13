int ninjaTraining(int n, vector<vector<int>> &points)
{
    int m=points[0].size();
    int dp[n][3];
    int maxi=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
          if (i == 0) {
            dp[i][j] = points[i][j];
          }

          else if (j == 0) {
            dp[i][j]=points[i][j]+max(dp[i-1][j+1],dp[i-1][j+2]);
          } else if (j == 1) {
            dp[i][j]=points[i][j]+max(dp[i-1][j-1],dp[i-1][j+1]);
          } else if (j == 2) {
            dp[i][j] = points[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
            
          }
          if(i==n-1)
          maxi=max(maxi,dp[i][j]);
        }
    }
    return maxi;
}
