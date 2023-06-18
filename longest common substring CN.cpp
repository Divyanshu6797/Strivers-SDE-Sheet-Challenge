#include <bits/stdc++.h> 

// extended indexing
int lcs(string &str1, string &str2){
	
	int n1=str1.size();
	int n2=str2.size();

	vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0;
		}
	}

	int maxi=0;
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(str1[i-1]==str2[j-1])    // extended indexing
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=0;

			maxi=max(maxi,dp[i][j]);
			
		}
	}
	return maxi;
}
