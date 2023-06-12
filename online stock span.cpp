#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    stack<pair<int,int>> stk;
    vector<int> v;

    for (int i = 0; i < price.size(); i++) {
        int days=1;
        while(!stk.empty() && stk.top().first<=price[i])
        {
            days+=stk.top().second;
            stk.pop();
        }
        stk.push(make_pair(price[i],days));
        v.push_back(days);
    }
    return v;
}
