#include <bits/stdc++.h> 

/* using DFS traversal but it gives TLE idk why
void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> grid,int n,int m,vector<int> deltaR,vector<int> deltaC)
{
    vis[i][j]=1;

    for(int q=0;q<8;q++)
    {
        int nrow=i+deltaR[q];
        int ncol=j+deltaC[q];
        if(nrow>=0 && nrow<n && ncol<m && ncol>=0)
        {
            if(!vis[nrow][ncol] && grid[nrow][ncol]==1)
            dfs(nrow,ncol,vis,grid,n,m,deltaR,deltaC);
        }
    }


}
int numberOfIslands(vector<vector<int>>& grid, int n, int m)
{
    int count=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int> deltaR={0,+1,+1,+1,0,-1,-1,-1};
    vector<int> deltaC={-1,-1,0,+1,+1,+1,0,-1};
    
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(!vis[i][j] && grid[i][j]==1)
           {
               count++;
               dfs(i,j,vis,grid,n,m,deltaR,deltaC);
           }
       }
   }
   return count;
}
*/

// uisng  BFS traversal
void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> grid,int n,int m,vector<int> deltaR,vector<int> deltaC)
{
    vis[i][j]=1;
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));

    while(!q.empty())
    {
        pair<int,int> temp=q.front();
        q.pop();

        int row=temp.first;
        int col=temp.second;

        for(int w=0;w<8;w++)
        {
            int nrow=row+deltaR[w];
            int ncol=col+deltaC[w];
            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]==1)
        {
            vis[nrow][ncol]=1;
           q.push(make_pair(nrow,ncol));
        }
        }
    }



}
int numberOfIslands(vector<vector<int>>& grid, int n, int m)
{
    int count=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int> deltaR={0,+1,+1,+1,0,-1,-1,-1};
    vector<int> deltaC={-1,-1,0,+1,+1,+1,0,-1};
    
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(!vis[i][j] && grid[i][j]==1)
           {
               count++;
               bfs(i,j,vis,grid,n,m,deltaR,deltaC);
           }
       }
   }
   return count;
}

