  class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,-1}});
        int sum=0;
        
        while(!pq.empty())
        {
            auto itr=pq.top();
            pq.pop();
            
            int wt=itr.first;
            int node=itr.second.first;
            int parent=itr.second.second;

            
            if(vis[node]==1)  continue;
            vis[node]=1;
                        sum+=wt;
            
            
            for(auto it : adj[node])
            {
                if(!vis[it[0]])
                {
                    pq.push({it[1],{it[0],node}});
                }
            }
            
            
        }
        
        return sum;
        
        
    }
};
