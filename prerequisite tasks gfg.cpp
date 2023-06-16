class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    int p=prerequisites.size();
	    vector<int> adj[N];
	    for(int i=0;i<p;i++)
	    {
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        
	    }
	    
	    queue<int> q;
	   int indegree[N]={0};
	    
	    for(int i=0;i<N;i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    int count=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        count++;
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	        
	    }
	    if(count==N)
	    return true;
	    else
	    return false;
	}
};
