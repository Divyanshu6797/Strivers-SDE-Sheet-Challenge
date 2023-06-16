class Solution {
private:

bool dfs(int i,int color[],vector<int> adj[], int col)
{
    color[i]=col;
    
    for(auto it : adj[i])
    {
        if(color[it]==-1)
        {
            if(dfs(it,color,adj,!col)==false)
            return false;
        }
        else if(color[it]==color[i])
        {
        return false;
        }
    }
    return true;
}

 bool bfs(int i,int color[],vector<int> adj[])
{
    color[i]=0;
    
    queue<int> q;
    q.push(i);
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto it : adj[node])
        {
            if(color[it]==-1)
            {
            color[it]=!color[node];
            q.push(it);
            }
            else if(color[it]==color[node])
            return false;
        }
    }
    
    return true;
    
}

public:

	bool isBipartite(int V, vector<int>adj[]){
	   int color[V];
	    for(int i=0;i<V;i++)
	    {
	        color[i]=-1;
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	             //if(bfs(i,color,adj)==false)    
	           
	          if(dfs(i,color,adj,0)==false)   
	            return false;
	            
	        }
	    }
	    return true;
	    
	    
	}

};
