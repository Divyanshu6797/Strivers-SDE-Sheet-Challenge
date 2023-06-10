#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    
    vector<vector<int>>ans;
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());

    if(n==0)
    return ans;
    else if(n==1)
    {
      vector<int> temp = { intervals[0][0], intervals[0][1] };
      ans.push_back(temp);
      return ans;
    }

    for(int i=1;i<n;i++)
    {
      if(intervals[i][0]<=intervals[i-1][1])
      {
          intervals[i][0]=intervals[i-1][0];
          intervals[i][1]=max(intervals[i][1],intervals[i-1][1]);
          
      }
      else
      {
        vector<int> temp = { intervals[i - 1][0], intervals[i - 1][1] };
        ans.push_back(temp);

      }

      if(i==n-1)
      {
          vector<int>temp={intervals[i][0],intervals[i][1]};
          ans.push_back(temp);
      }
      
      

    }
    return ans;
}
