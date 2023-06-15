void dfs(int vertex,vector<int>&ans,vector<int> adj[],vector<int> &vis)
{
    ans.push_back(vertex);
    vis[vertex]=1;
    
    for(auto it: adj[vertex])
    {
        if(!vis[it])
        dfs(it,ans,adj,vis);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(int i=0;i<E;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V,0);
        vector<vector<int>> ans;

        for(int i=0;i<V;i++)
        {
          if (!vis[i]) 
          {
              vector<int> v;
            dfs(i, v, adj, vis);
            ans.push_back(v);
          }
        }
        return ans;
}
