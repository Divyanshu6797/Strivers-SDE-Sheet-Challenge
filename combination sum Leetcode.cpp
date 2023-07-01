class Solution {
public:

   void f(int i,int target,int n,vector<int>& candidates,vector<int> &temp,vector<vector<int>> &ans)
   {

       if(i==n)
       {
           if(target==0)
           {
               ans.push_back(temp);
           }

           return ;
       }

       temp.push_back(candidates[i]);
       if(candidates[i]<=target)                        
       {

           f(i,target-candidates[i],n,candidates,temp,ans);          //take

       }

       temp.pop_back();

       f(i+1,target,n,candidates,temp,ans);           // not take
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n=candidates.size();
        
        vector<vector<int>> ans;
        vector<int> temp;

        f(0,target,n,candidates,temp,ans);
        return ans;
    }
};
