vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());

	for(int i=0;i<n;i++)
	{
		if(i>0 && arr[i]==arr[i-1]) continue;
		int j=i+1;
		int q=n-1;

		while(j<q)
		{
			int sum=arr[i]+arr[j]+arr[q];
			if(sum<K)
			j++;
			else if(sum>K)
			q--;
			else{
				vector<int> temp={arr[i],arr[j],arr[q]};
				ans.push_back(temp);
				j++;
				q--;

				while(arr[j-1]==arr[j]) j++;
				while(arr[q]==arr[q+1]) q--;
			}
		}
	}
	return ans;
	
	
}
