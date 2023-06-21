class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int mod=100000;
        
        
        queue<pair<int,int>> q;
        q.push({0,start});
        
        vector<int> dist(100000,1e9);
        dist[start]=0;
        
        while(!q.empty())
        {
            int steps=q.front().first;
            int node=q.front().second;
            
            q.pop();
            
            for(auto it : arr)
            {
                int mul=(it*node)%mod;
                
                if(steps+1<dist[mul])
                {
                    dist[mul]=steps+1;
                    q.push({steps+1,mul});
                    
                    if(mul==end)
                    {
                        return dist[mul];
                        }
                }
            }
        }
        return -1;
        
        
        
    }
};
