class Solution
{
    /*  dfs algorithm using stack
    private :
    
    void dfs(int i, vector<int> adj[],int vis[],stack<int>&stk)
    {
        vis[i]=1;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,stk);
            }
        }
        stk.push(i);
       
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> stk;
	    
	    int vis[V]={0};
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,adj,vis,stk);
	        }
	        
	    }
	    vector<int> ans;
	    
	    while(!stk.empty())
	    {
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    return ans;
	}
	*/
	
	
	

  
    
	public:
	
	// Kahn's algorithm using bfs and indegree
	 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    int indegree[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto it : adj[i])
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
	    vector<int> ans;
	    
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
	    return ans;
	    
	}
};
