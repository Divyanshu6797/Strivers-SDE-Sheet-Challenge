class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
       	   
	    vector<int> adj[n];
	    for(int i=0;i<m;i++)
	    {
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	        
	    }
	    
	    queue<int> q;
	    vector<int> ans;
	   int indegree[n]={0};
	    
	    for(int i=0;i<n;i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<n;i++)
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
	        
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	        
	    }
	    int count=ans.size();
	    if(count==n)
	    {
	        return ans;
	    }
	    else
	    {
	        vector<int> bogus;
	        return bogus;
	    }
    }
};
