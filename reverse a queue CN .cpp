#include <bits/stdc++.h> 
void reverse(queue < int > & q) {
    /* using stack
    stack<int> stk;

    while(!q.empty())
    {
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }
    */

    // using recursion

    if(q.empty())
    return ;

    int num=q.front();
    q.pop();

    reverse(q);
    q.push(num);
}
