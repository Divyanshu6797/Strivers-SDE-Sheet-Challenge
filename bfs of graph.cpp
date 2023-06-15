#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    int n=edges.size();

    vector<int> adj[vertex];
    for(int i=0;i<n;i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
        
    }
    for(int i=0;i<vertex;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    
    


    int vis[vertex]={0};
    
    queue<int>q;
    
    vector<int> bfs;
for(int i=0;i<vertex;i++)
{
    if(!vis[i])
    {
        vis[i]=1;
        q.push(i);
    


    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it: adj[node])
        {
          if (!vis[it]) {
            vis[it] = 1;
            q.push(it);
          }
        }
    }
    }
}

    return bfs;
}
