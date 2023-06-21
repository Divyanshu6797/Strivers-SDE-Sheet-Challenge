class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int price=flights[i][2];
            
            adj[u].push_back({v,price});
            
         }
    
    queue<pair<int,pair<int,int>>> q;
    
    vector<int> cost(n,1e9);
    cost[src]=0;
    
    q.push({0,{src,0}});
    
    while(!q.empty())
    {
        auto itr=q.front();
        q.pop();
        int place=itr.second.first;
        int price=itr.second.second;
        int stops=itr.first;
        
       
        
        
      
        
       if(stops>K) continue; 
       
            for(auto it : adj[place])
            {
                int adjacentPlace=it.first;
                int adjacentCost=it.second;
                
                if(adjacentCost+price<cost[adjacentPlace])
                {
                    cost[adjacentPlace]=adjacentCost+price;
                    q.push({stops+1,{adjacentPlace,cost[adjacentPlace]}});
                }
            }
            
        
    }
    if(cost[dst]==1e9)
   
   return -1;
   
   return cost[dst];
   
}
};
