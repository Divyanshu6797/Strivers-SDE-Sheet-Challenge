#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	int i=m-1;
	int j=0;
	while(i>=0 && j<n)
	{
		if(arr1[i]>arr2[j])
		{
			swap(arr1[i],arr2[j]);
			i--;
			j++;
		}
		else
		 break;
	}
	sort(arr1.begin(),arr1.begin()+m);
	sort(arr2.begin(),arr2.end());

	for(int k=0;k<n;k++)
	{
		arr1[m+k]=arr2[k];
	}
	return arr1;
}
