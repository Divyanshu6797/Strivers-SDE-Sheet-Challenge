vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	
	set<vector<int>> st;
	for(int i=0;i<n;i++)
	{
		set<int>h;                       //map can also be used here
		for(int j=i+1;j<n;j++)
		{
			int target=K-arr[i]-arr[j];
			if(h.find(target)!=h.end())
			{
				vector<int> temp={arr[i],arr[j],target};
				sort(temp.begin(),temp.end());
				st.insert(temp);


			}
			h.insert(arr[j]);
		}



	}
	vector<vector<int>> v(st.begin(),st.end());

return v;
}
