  #include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
unordered_map<int,int> umap;
int n=nums.size();
int x;
for(int i=0;i<n;i++)
{
    x=target-nums[i];
    if(umap.find(x)==umap.end())
    {
      umap[nums[i]]=i;
    }
    else
  return {i,umap[x]};

}
return {-1,-1};


    }
    
};
