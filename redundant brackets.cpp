#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<int> stk;
    
    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='/' || ch=='*' )
        {
            stk.push(s[i]);
        }
        else if(ch==')')
        {
            if(stk.top()=='(')
            return true;

            while(stk.top()!='(')
            {
                stk.pop();
            }
            stk.pop();
        }
        

    }
    return false;
}
