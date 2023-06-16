class Solution
{
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
};
