#include<bits/stdc++.h>
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n=arr.size();
    int sum=0;
    int prefix[n];
    int count=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        count++;
         prefix[i]=sum;

         m[prefix[i]]++;

         if(m.find(prefix[i]-k)!=m.end())
         count+=m[prefix[i]-k];


    }
    return count;


}
