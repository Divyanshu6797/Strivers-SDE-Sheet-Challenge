class DisjointSet 
{
    vector<int> parent,rank,size;
    
    public :
    
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,1);
        
        for(int i=0;i<n;i++)  parent[i]=i;
    }
     int getUparent(int node)
     {
         if(parent[node]==node)
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
         return ;
         
         if(size[up_u]<size[up_v])
         {
             size[up_v]+=size[up_u];
             parent[up_u]=up_v;
         }
         else
         {
             size[up_u]+=size[up_v];
             parent[up_v]=up_u;
         }
         
     }
};

class Solution {
    /*using dfs
    
    private:
    void dfs(int start,vector<int> a[],int vis[])
    {
       
            vis[start]=1;
      
        for(auto it : a[start])
        {
            if(!vis[it])
            dfs(it,a,vis);
            
            
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        // making adjacency list from adjacency matrix given
        vector<int> a[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        
        int count=0;
        int vis[V]={0};
        
        for(int i=0;i<V;i++)
        {
         if(vis[i]==0)
         {
             count++;
             dfs(i,a,vis);
         }
        }
        return count;
        
         }
         */
         
         // Disjoint set
         
         public: 
          int numProvinces(vector<vector<int>> adj, int V) {
              DisjointSet ds(V);
        
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           {
               if(adj[i][j]==1)
               {
                   ds.UnionBySize(i,j);
                   
               }
               
           }
       }
       int cnt=0;
       for(int i=0;i<V;i++)
       {
           if(ds.getUparent(i)==i)
           cnt++;
       }
       return cnt;
       
       
       
         }
};
