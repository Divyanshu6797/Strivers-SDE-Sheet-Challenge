class DisjointSet
{
    public :
    
    vector<int> rank,size,parent;
    
    DisjointSet(int n)
    {
        rank.resize(n,0);
        size.resize(n,1);
        
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int getUparent(int node)
    {
        if(node==parent[node])
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
        else if(rank[up_u]<=rank[up_v])
        {
            parent[up_u]=up_v;
        }
        else
        {
            parent[up_v]=up_u;
        }
        
        
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
  
  bool isValid(int i,int j,int n,int m)
  {
      if(i<n && i>=0 && j<m && j>=0)
      return true;
      else
      return false;
  }
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
        DisjointSet ds(n*m);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int q=0;q<4;q++)
                    {
                        int nrow=i+delr[q];
                        int ncol=j+delc[q];
                        
                        if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==1)
                        {
                            int node=(i*m)+j;
                            int adjnode=(nrow*m)+ncol;
                            
                            ds.unionBySize(node,adjnode);
                        }
                        
                    }
                    
                }
            }
        }
        
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int> s;
                    for(int q=0;q<4;q++)
                    {
                        int nrow=i+delr[q];
                        int ncol=j+delc[q];
                        
                        if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==1)
                        {
                            s.insert(ds.getUparent((nrow*m)+ncol));
                        }
                    }
                    int sum=1;
                    
                    for(auto it:s)
                    {
                        sum=sum+ds.size[it];
                        
                    }
                    maxi=max(sum,maxi);
                }
            }
        }
        
        for(int i=0;i< m*n ;i++)
        {
            maxi=max(ds.size[i],maxi);
        }
        
        return maxi;
        
        
        
        
    }
};
