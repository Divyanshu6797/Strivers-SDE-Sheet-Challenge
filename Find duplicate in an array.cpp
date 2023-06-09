#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	int freq[n]={0};

	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
		if(freq[arr[i]]>1)
		return arr[i];
	}
}
