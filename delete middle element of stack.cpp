class Solution
{
    private :
    void solve(stack<int> &s, int count,int n)
    {
        if(count==n/2)
        {
        s.pop();
        return;
        }
        
        int temp=s.top();
        s.pop();
        solve(s,count+1,n);
        s.push(temp);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
       solve(s,0,sizeOfStack);
    }
};
