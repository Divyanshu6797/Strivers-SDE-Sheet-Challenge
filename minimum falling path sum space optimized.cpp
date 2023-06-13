#include <bits/stdc++.h> 
using namespace std;
int minFallingPathSum(vector<vector<int>> &vec, int n) {
    vector<int> prev(n,0);
    int mini=INT_MAX;

    for(int i=0;i<n;i++)
    {
        vector<int> curr(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0) curr[j]=vec[i][j];
            else{ 
                int left=INT_MAX;
                int right =INT_MAX;
                int middle=prev[j];

                if(j>0) left=prev[j-1];
                if(j<n-1) right=prev[j+1];
                curr[j]=min(min(left,right),middle)+vec[i][j];
            }
        }
        prev=curr;
        
    }
    for(int i=0;i<n;i++)
    {
        mini=min(mini,prev[i]);
    }
    return mini;
}
