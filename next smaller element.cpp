#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans;
    stack<int> stk;

    for(int i=n-1;i>=0;i--)
    {
        while(!stk.empty() && stk.top()>=arr[i])
        {
            stk.pop();
        }
       if(stk.empty())
       ans.push_back(-1);
       else
       ans.push_back(stk.top());

       stk.push(arr[i]);

    }
    reverse(ans.begin(),ans.end());
    return ans;

    
}
