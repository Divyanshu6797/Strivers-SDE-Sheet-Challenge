#include <bits/stdc++.h> 
vector<int> divisibleSet(vector<int> &arr){
    
    int n=arr.size();
   sort(arr.begin(),arr.end());
   vector<int> hash(n,1);
  
   vector<int> dist(n,1);


   
   

   for(int i=0;i<n;i++)
   {
       hash[i]=i;
       for(int j=0;j<i;j++)
       {
           if(arr[i] % arr[j]==0 && 1+dist[j]>dist[i])
           {
               dist[i]=1+dist[j];
               hash[i]=j;
               
           }
           
       }
      
   }
   int temp=-1;
   int lastindex=-1;

   for(int i=0;i<n;i++)
   {
     if (dist[i] > temp) {
         temp=dist[i];
       lastindex = i;
     }
   }

   vector<int> ans;
   ans.push_back(arr[lastindex]);

   while(hash[lastindex]!=lastindex)
   {
       lastindex=hash[lastindex];
       ans.push_back(arr[lastindex]);
   }
   reverse(ans.begin(),ans.end());
   return ans;

   
}
