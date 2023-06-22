#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  if(str.size()%2!=0)
  return -1;

  stack<char> stk;

  for(int i=0;i<str.size();i++)
  {
    char ch=str[i];
    if(str[i]=='{')
    stk.push(ch);

    else {
      if(!stk.empty() && stk.top()=='{' )
        stk.pop();

        else stk.push(ch);
    }
  }
  int a=0;
  int b=0;

  while(!stk.empty())
  {
    if(stk.top()=='{')
    a++;
    else
    b++;
    
    stk.pop();
  }
  return ((a+1)/2)+((b+1)/2);
}
