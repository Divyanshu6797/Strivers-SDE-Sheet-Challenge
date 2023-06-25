class DisjointSet
{
    public :
    
    vector<int> rank,size,parent;
    
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
        if(parent[node]==node)
        return node;
        
        else
        return parent[node]= getUparent(parent[node]);
    }
    
    void unionBySize(int u, int v)
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
        {
            parent[up_v]=up_u; 
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DisjointSet ds(n*m);
        
      
        
        int vis[n][m];
        vector<int> ans;
        memset(vis,0,sizeof vis);
        
        int count=0;
        
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
       for(auto it:operators)
       {
           int row=it[0];
           int col=it[1];
           
           if(vis[row][col]==1)
           {
               ans.push_back(count);
               continue;
           }
           vis[row][col]=1;
           count++;
           
           for(int i=0;i<4;i++)
           {
               int nrow=row+delr[i];
               int ncol=col+delc[i];
               
               if(isValid(nrow,ncol,n,m) && vis[nrow][ncol]==1)
               {
                   int node=(m*row)+col;
                   
                   int adjnode=(nrow*m)+ncol;
                   if(ds.getUparent(node)!=ds.getUparent(adjnode))
                   {
                       count--;
                       ds.unionByRank(node,adjnode);
                   }
                   
               }
           }
           ans.push_back(count);
       }
       return ans;
    }
};
