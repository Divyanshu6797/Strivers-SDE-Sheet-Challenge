class Solution {
    /* using priority queue
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int distance=edges[i][2];
            
            adj[u].push_back({v,distance});
            adj[v].push_back({u,distance});
        }
        
       
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;  // min heap
        
        vector<int> dist(n+1,1e9);
        dist[1]=0;
        
        vector<int> parent(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        
       
        
        
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it: adj[node])
            {
                int adjacentNode=it.first;
                int distance=it.second;
                
                if(wt+distance < dist[adjacentNode])
                {
                    dist[adjacentNode]=wt+distance;
                    pq.push({dist[adjacentNode],adjacentNode});
                    parent[adjacentNode]=node;
                
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        int node=n;
        vector<int> ans;
        
        if(node==parent[node])  return {-1};  // if no path is possible
        
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
        
        
    }
    
    */
     public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int distance=edges[i][2];
            
            adj[u].push_back({v,distance});
            adj[v].push_back({u,distance});
        }
        set<pair<int,int>> st;
        
        vector<int> dist(n+1,1e9);
        dist[1]=0;
        
        vector<int> parent(n+1,-1);
        
        for(int i=1;i<=n;i++)  parent[i]=i;
        
        st.insert({0,1});
        
        while(!st.empty())
        {
            auto itr=*(st.begin());
            int wt=itr.first;
            int node=itr.second;
            
            st.erase(itr);
            
            for(auto it: adj[node])
            {
                int adjacentNode=it.first;
                int distance=it.second;
                
                if(wt+distance<dist[adjacentNode])
                {
                    if(dist[adjacentNode]!=1e9)
                    {
                    st.erase({dist[adjacentNode],adjacentNode});
                    }
                    dist[adjacentNode]=wt+distance;
                    st.insert({dist[adjacentNode],adjacentNode});
                    parent[adjacentNode]=node;
                }
            }
            
        }
           int node=n;
            if(parent[node]==node)  return{-1};
           
            
            vector<int> ans;
            
            while(node!=parent[node])
            {
                ans.push_back(node);
                node=parent[node];
                
            }
            ans.push_back(1);
            
            reverse(ans.begin(),ans.end());
            
            return ans;
        
    }
};
