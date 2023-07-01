#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

	int count=0;
	int el;

	for(int i=0;i<v.size();i++)
	{
		if(count==0)
		{
			el=v[i];
			count=1;
		}
		else if(el!=v[i])
		{
			count--;

		}
		else
		{
			count++;
		}
	}

	int cnt=0;
	for(int i=0;i<v.size();i++)
	{
		if(el==v[i])
		{
			cnt++;
		}

	}
	if(cnt>v.size()/2)
	{
		return el;
	}


}
