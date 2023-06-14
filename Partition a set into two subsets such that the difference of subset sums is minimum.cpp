#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int mini=INT_MAX;

	int target=0;
	for(int i=0;i<n;i++)
	{
		target+=arr[i];
	}
	vector<vector<bool>> dp(n,vector<bool>(target+1,false));

	for(int i=0;i<n;i++)
	{
		dp[i][0]=true;
	}
	if(arr[0]<=target)
	dp[0][arr[0]]=true;

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=target;j++)
		{
			bool up=dp[i-1][j];
			bool upleft=false;
			if(arr[i]<=j)
			{
				upleft=dp[i-1][j-arr[i]];
			}
			dp[i][j]= up | upleft;
		}

	}
	for(int i=0;i<=target;i++)
	{
		if(dp[n-1][i]==true)
		{
			mini=min(mini,abs(target-2*i));
		}
	}
	return mini;

}
