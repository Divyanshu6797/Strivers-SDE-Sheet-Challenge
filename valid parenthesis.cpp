#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> stk;
    stk.push(expression[0]);

    for(int i=1;i<expression.length();i++)
    {
        char ch=expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
          stk.push(ch);
        }
         else // for closing parenthesis
         {
          if (!stk.empty()) {
            int b = stk.top();
            if ((ch == ')' && b == '(') || (ch == '}' && b == '{') ||
                (ch == ']' && b == '[')) {
              stk.pop();
            } else
              return false;

          } else
            return false;
        }
    }

          if (stk.empty())
            return true;

        return false;
    
}
