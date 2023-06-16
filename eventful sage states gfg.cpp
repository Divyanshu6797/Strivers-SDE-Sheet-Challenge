class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adj1[V];
     for(int i=0;i<V;i++)
     {
         for(auto it: adj[i])
         {
             adj1[it].push_back(i);
             
         }
         
     }
     adj=adj1;
     
     vector<int> ans;
     int indegree[V]={0};
     
     for(int i=0;i<V;i++)
     {
         for(auto it: adj[i])
         {
             indegree[it]++;
         }
     }
     queue<int> q;
     for(int i=0;i<V;i++)
     {
         if(indegree[i]==0)
         {
             q.push(i);
         }
     }
     
     while(!q.empty())
     {
         int node=q.front();
         q.pop();
         ans.push_back(node);
         
         for(auto it: adj[node])
         {
             indegree[it]--;
             if(indegree[it]==0)
             q.push(it);
         }
         
     }
     sort(ans.begin(),ans.end());
     return ans;
    }
};
