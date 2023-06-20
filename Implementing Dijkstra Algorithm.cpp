class Solution
{
    /* using priority queue
	public:

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
    
    vector<int> dist(V,1e9); 
    
    dist[S]=0;
   
    
    
    
    pq.push({dist[S],S});
    
    while(!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second;
        
        pq.pop();
        
        for(auto it : adj[node])
        {
            int adjnode=it[0];
            
            if(wt+it[1]<dist[adjnode])
            {
                dist[adjnode]=wt+it[1];
                pq.push({wt+it[1],adjnode});
               
            }
        }
        
        
    }
    for(int i=0;i<V;i++)
    {
        if(dist[i]==1e9)
        dist[i]=-1;
    }
    return dist;
    
    }
    */
    
    
    // using sets  ->   most effecient  E log V
    public:

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       set<pair<int,int> >  st;                   // dist,node
       vector<int> dist(V,1e9);     dist[S]=0;
       
       st.insert({0,S});
       
       while(!st.empty())
       {
           auto itr=*(st.begin());
           
           int wt=itr.first;
           int node=itr.second;
           st.erase(itr);
           
           for(auto it: adj[node])
           {
               int adjacentNode=it[0];
               int distance=it[1];
               
               if(wt+distance < dist[adjacentNode])
               {
                  
                   if(dist[adjacentNode]!=1e9)
                   {
                       st.erase({dist[adjacentNode],adjacentNode});
                   }
                    dist[adjacentNode]=wt+distance;
                   st.insert({dist[adjacentNode],adjacentNode});
               }
           }
       }
       
       for(int i=0;i<V;i++)
       {
           if(dist[i]==1e9)
           dist[i]=-1;
       }
         return dist;
    }
       
     
};
