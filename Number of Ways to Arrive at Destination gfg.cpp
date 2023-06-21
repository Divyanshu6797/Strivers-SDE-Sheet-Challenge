class Solution {
    
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod=(int)(1e9+7);
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({0,0});
        
        vector<int> ways(n,0);
        ways[0]=1;
        
        vector<long long> dist(n,1e15);
        dist[0]=0;
        
        while(!pq.empty())
        {
            auto itr=pq.top();
            pq.pop();
            
            int dis=itr.first;
            int node=itr.second;
            
            for(auto it: adj[node])
            {
                int adjacentNode=it.first;
                int distance=it.second;
                
                if(dis+distance<dist[adjacentNode])
                {
                    dist[adjacentNode]=dis+distance;
                    pq.push({dist[adjacentNode],adjacentNode});
                    ways[adjacentNode]=ways[node];
                    
                }
                else if(dis+distance==dist[adjacentNode])
                {
                    ways[adjacentNode]=(ways[adjacentNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
        
    }
};
