#include<bits/stdc++.h>

bool bfs(int src,vector<int> adj[],vector<int>&vis)
{
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});

    while(!q.empty())
    {
        

        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjacentnode:adj[node])
        {
            if(!vis[adjacentnode])
            {
                vis[adjacentnode]=1;

                q.push({adjacentnode,node});
            }
            else if(adjacentnode!=parent)
            {
                return true;
            }
        }
    }
    return false;


}


bool dfs(int node,int parent,vector<int> adj[],vector<int>&vis)
{
    vis[node]=1;

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,node,adj,vis)) return true;
        }
        else if(it!=parent) return true;
    }
    return false;

}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];

    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];

       int v=edges[i][1];

       adj[u].push_back(v);

       adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            /* if(bfs(i,adj,vis)) return "Yes";  */ 

              if(dfs(i,-1,adj,vis))  return "Yes";
        }

    }
  
    return "No";

}
