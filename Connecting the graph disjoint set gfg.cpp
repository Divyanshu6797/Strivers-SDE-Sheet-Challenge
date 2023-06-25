class DisjointSet
{
    private :
    vector<int> parent,size,rank;
    
    public:
    DisjointSet(int n)
    {
        size.resize(n,1);
        rank.resize(n,0);
        
        parent.resize(n);
        
        for(int i=0;i<n;i++)  parent[i]=i;
        
    }
    
    int getUparent(int node)
    {
        if(parent[node]==node)
        return node;
        else
        return parent[node]=getUparent(parent[node]);
    }
    
    void unionByRank(int u,int v)
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
        parent[up_v]=up_u;
    }
    
    void unionBySize(int u,int v)
    {
        int up_u=getUparent(u);
        int up_v=getUparent(v);
        
        if(up_u==up_v)
        return ;
        
        if(size[up_u]<size[up_v])
        {
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else
        {
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int freeedges=0;
        
        for(auto it:edge)
        {
            if(ds.getUparent(it[0])==ds.getUparent(it[1]))
            {
                freeedges++;
            }
            ds.unionByRank(it[0],it[1]);
            
            
            
        }
        int nodc=0;             // no of disconnected components
        
        for(int i=0;i<n;i++)
        {
            if(ds.getUparent(i)==i)
            nodc++;
        }
        if(freeedges>=nodc-1)
        return nodc-1;
        else
        return -1;
        
    }
};
