int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    

   int dp[n][m];

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(mat[i][j]==-1)
           {
               dp[i][j]=0;
           }
           else if(i==0 && j==0)
           {
               dp[i][j]=1;

           }
            else
             {
             int right = 0;
             int down = 0;
             if (i > 0)
               down = dp[i - 1][j];
             if (j > 0)
               right = dp[i][j - 1];

             dp[i][j] = (down + right)%mod;
           }
       }
   }
   return dp[n-1][m-1];
}
