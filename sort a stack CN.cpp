#include <bits/stdc++.h> 
void insertSort(stack<int> &stack,int x)
{
  if (stack.empty()) {
	  stack.push(x);
	  return;
  }
int num;
        if(x>stack.top())
	{
		stack.push(x);
		return;

        } else {
          num = stack.top();
          stack.pop();
		  insertSort(stack,x);
        }

		stack.push(num);

}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return ;
	}

	int num=stack.top();
	stack.pop();

	sortStack(stack);

	insertSort(stack,num);

}
