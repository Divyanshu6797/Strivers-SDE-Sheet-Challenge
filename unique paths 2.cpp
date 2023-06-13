int mod=(int) (1e9+7);

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    

    int dp[n][m];
    if(mat[0][0]==-1)
    return 0;
    if(mat[n-1][m-1]==-1)
    return 0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(flag)
        {
            dp[i][0]=0;

        }
        else if (mat[i][0]==-1)
        {
            dp[i][0]=0;
            flag=1;
        }
        else
        {
            dp[i][0]=1;
        }

    }
    flag=0;

    for(int i=1;i<m;i++)
    {
        if(flag)
        {
            dp[0][i]=0;

        }
        else if (mat[0][i]==-1)
        {
            dp[0][i]=0;
            flag=1;
        }
        else
        {
            dp[0][i]=1;
        }

    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j]==-1)
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    return dp[n-1][m-1];

}
