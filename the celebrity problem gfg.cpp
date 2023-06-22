class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> stk;
        
        for(int i=0;i<n;i++)
        {
            stk.push(i);
        }
        
        while(stk.size()>1)
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            
            if(M[a][b]==1)
            {
                stk.push(b);
            }
            else
            stk.push(a);
        }
        
        int celeb=stk.top();
        stk.pop();
        
        // check is celeb is really a celeb
        
        for(int i=0;i<n;i++)
        {
            if(M[celeb][i]==1)
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            if(celeb!=i)
            {
                if(M[i][celeb]==0)
                return -1;
            }
        }
        
        return celeb;
    }
};
