class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        
        if(n-1==0 && m-1==0)
        return 0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
        q.push({0,{0,0}});
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};
        
        while(!q.empty())
        {
            auto itr=q.top();
            q.pop();
            
            int diff=itr.first;
            
            int nodei=itr.second.first;
            int nodej=itr.second.second;
            
             if(nodei==n-1 && nodej==m-1)
                return dist[nodei][nodej];
            
            for(int i=0;i<4;i++)
            {
                int nrow=nodei+delr[i];
                int ncol=nodej+delc[i];
                
               
                
                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m)
                {
                    int newdiff=max(diff,abs(heights[nrow][ncol]-heights[nodei][nodej]));
                    if(newdiff<dist[nrow][ncol])
                    {
                        dist[nrow][ncol]=newdiff;
                        q.push({newdiff,{nrow,ncol}});
                    }
                }
            }
            
            
            
            
        }

        
        
        
        
    }
};
