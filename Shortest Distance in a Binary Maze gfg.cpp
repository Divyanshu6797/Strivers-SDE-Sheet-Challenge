class Solution {
  public:
  
  // using Dijkastra algorithm
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
                         if(source == destination)
                         return 0;
                         
                         int n=grid.size();
                         int m=grid[0].size();
                         
                         
                         queue<pair<int,pair<int,int>>> pq;
                         pq.push({0,{source.first,source.second}});
                         
                         vector<vector<int>> dist(n,vector<int>(m,1e9));
                         dist[source.first][source.second]=0;
                         
                         int delr[]={1,0,-1,0};
                         int delc[]={0,+1,0,-1};
                         
                         while(!pq.empty())
                         {
                             auto itr=pq.front();
                             pq.pop();
                             
                             int wt=itr.first;
                             int nodei=itr.second.first;
                             int nodej=itr.second.second;
                             
                             for(int w=0;w<4;w++)
                             {
                               int nrow=nodei+delr[w];
                               int ncol=nodej+delc[w];
                               
                               if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 1+wt<dist[nrow][ncol])
                               {
                                   if(nrow==destination.first && ncol==destination.second)  return 1+wt;
                                   
                                   dist[nrow][ncol]=1+wt;
                                   pq.push({1+wt,{nrow,ncol}});
                               }
                               
                               
                                 
                             }
                             
                             
                         }
                         return -1;
                         
    }
};
