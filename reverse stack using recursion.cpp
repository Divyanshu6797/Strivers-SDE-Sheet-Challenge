class Solution{
    private :
    void help(stack<int> &st,int element)
    {
        if(st.empty())
        {
            
        
        st.push(element);
        return ;
        }
        
        int temp=st.top();
        st.pop();
        
        help(st,element);
        
        st.push(temp);
        
        
    }
public:
    void Reverse(stack<int> &st){
        
        if(st.empty())
        return ;
        
        int num=st.top();
        st.pop();
        
        Reverse(st);
        
        help(st,num);
        
    }
};
