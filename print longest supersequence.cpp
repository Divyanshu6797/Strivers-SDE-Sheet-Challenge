#include <bits/stdc++.h> 

//extended indexing
string shortestSupersequence(string a, string b)
{
	int n1=a.size();
	int n2=b.size();

	vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

	for(int i=0;i<=n1;i++)
	{
          for (int j = 0; j <= n2; j++)
		   {
            if (i == 0 || j == 0)
              dp[i][j] = 0;
          }
        }
		for(int i=1;i<=n1;i++)
	    {
                  for (int j = 1; j <= n2; j++) 
				  {
					  if(a[i-1]==b[j-1])            // extended indexing
					  dp[i][j]=1+dp[i-1][j-1];
					  else
					  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                  }
        }
		string ans="";
		
		int i=n1;
		int j=n2;

		while(i>0 && j>0)
		{
			if(a[i-1]==b[j-1])
			{
				ans=ans+a[i-1];
				i--;
				j--;
			}
			else if(dp[i-1][j]>dp[i][j-1])
			{
				ans=ans+a[i-1];
				i--;

                        }
						 else 
						{
                          ans = ans + b[j - 1];
                          j--;
                        }
                }

                while(i>0)
		{
			ans=ans+a[i-1];
			i--;
		}
		while(j>0)
		{
			ans=ans+b[j-1];
			j--;
		}

		reverse(ans.begin(),ans.end());
		return ans;







}
