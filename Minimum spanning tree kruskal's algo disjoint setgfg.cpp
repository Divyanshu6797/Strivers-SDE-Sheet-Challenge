class DisjointSet
{
    vector<int> rank,size,parent;
    
    public :
    DisjointSet(int n)
    {
        rank.resize(n,0);
        size.resize(n,1);
        parent.resize(n);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        
    }
    
    int getUparent(int node)
    {
        if(node==parent[node])
        return node;
        
        else
        return parent[node]= getUparent(parent[node]);
    }
    
    void UnionByRank(int u,int v)
    {
       
        int up_u=getUparent(u);
         int up_v=getUparent(v);
         
         if(rank[up_u]==rank[up_v])
         {
             parent[up_u]=up_v;
             rank[up_v]++;
         }
         else if(rank[up_u]<rank[up_v])
         {
             parent[up_u]=up_v;
         }
         else
         {
             parent[up_v]=up_u;
         }
        
    }
    
    void UnionBySize(int u,int v)
    {
         int up_u=getUparent(u);
         int up_v=getUparent(v);
         
         if(up_u==up_v)
         {
           return ;
         }
         if(size[up_u]<size[up_v])
         {
             parent[up_u]=up_v;
             
             parent[up_v]+=size[up_u];
         }
         else
         {
            parent[up_v]=up_u;
             
             parent[up_u]+=size[up_v];
         }
        
    }
};
class Solution
{ /* using prim's algorithm
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,-1}});
        int sum=0;
        
        while(!pq.empty())
        {
            auto itr=pq.top();
            pq.pop();
            
            int wt=itr.first;
            int node=itr.second.first;
            int parent=itr.second.second;

            
            if(vis[node]==1)  continue;
            vis[node]=1;
                        sum+=wt;
            
            
            for(auto it : adj[node])
            {
                if(!vis[it[0]])
                {
                    pq.push({it[1],{it[0],node}});
                }
            }
            
            
        }
        
        return sum;
        
        
    }
    */
    
    // using kruskal's algorithm
    public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                edges.push_back({it[1],{i,it[0]}});
            }
            
        }
        sort(edges.begin(),edges.end());
        
        DisjointSet ds(V);
        int sum=0;
        
        for(auto it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.getUparent(u)!=ds.getUparent(v))
            {
                sum=sum+wt;
            ds.UnionByRank(u,v);
                
            }
            
            
            
        }
        return sum;
    }
};
