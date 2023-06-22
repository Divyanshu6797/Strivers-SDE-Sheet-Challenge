class Solution{
    private :
    
    int largestArea(vector<int> &temp,int m)
    {
        vector<int> nextSmall(m,0);
        vector<int> prevSmall(m,0);
        int maxi=INT_MIN;
        
        //next small
        
        stack<int> st;
        st.push(-1);
        
        for(int i=m-1;i>=0;i--)
        {
            while(st.top()!=-1 && temp[st.top()]>=temp[i])
            {
             st.pop();   
            }
            nextSmall[i]=st.top();
            st.push(i);
            
        }
        
        // prev small
         stack<int> s;
        s.push(-1);
        
        for(int i=0;i<m;i++)
        {
            while(s.top()!=-1 && temp[s.top()]>=temp[i])
            {
             s.pop();   
            }
            prevSmall[i]=s.top();
            s.push(i);
            
        }
        
        for(int i=0;i<m;i++)
        {
            if(nextSmall[i]==-1)
            nextSmall[i]=m;
        }
        
        for(int i=0;i<m;i++)
        {
            maxi=max(maxi,temp[i]*(nextSmall[i]-prevSmall[i]-1));
        }
        return maxi;
        
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> temp1(m,0);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<int> temp(m,0);
            for(int j=0;j<m;j++)
            {
                if(i==0)
                {
                    temp[j]=M[i][j];
                   
                    
                }
                else
                {
                    if(M[i][j]==0)
                    temp[j]=0;
                    else
                    temp[j]=M[i][j]+temp1[j];
                }
                
            }
            maxi=max(maxi,largestArea(temp,m));
          
           
            temp1=temp;
            
        }
        return maxi;
    }
};
