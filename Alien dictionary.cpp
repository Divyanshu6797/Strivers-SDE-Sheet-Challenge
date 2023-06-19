class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i]; 
            string s2=dict[i+1];
            
            int n1=dict[i].size();
            int n2=dict[i+1].size();
            
            int len=min(n1,n2);
            
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
                
            }
        }
        
        
        int indegree[K]={0};
        
        for(int i=0;i<K;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        
        for(int i=0;i<K;i++)
        {
           
                if(indegree[i]==0)
                q.push(i);
            
        }
        vector<int> v;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            v.push_back(node);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                
                if(indegree[it]==0)
                q.push(it);
            }
        }
        string ans="";
        
        for(auto it: v)
        {
            ans=ans+char(it+'a');
        }
       return ans;
        
        
        
    }
};
