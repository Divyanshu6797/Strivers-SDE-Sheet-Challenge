vector < int > sortedArray(vector < int > a, vector < int > b) 
{

    int i=0;
    int j=0;
    
    int n=a.size();
    int m=b.size();

    vector<int> ans;

    while(i < n && j < m)
    {
        if(a[i]<b[j]) 
        {
           if(ans.size()==0 || ans.back()!=a[i])
           {
               ans.push_back(a[i]);
               
           }
           i++;
          

        }
        else 
        {
             if(ans.size()==0 || ans.back()!=b[j])
           {
               ans.push_back(b[j]);
            
           }
           j++;
          
            
        
        }

    }

    while(i<n)
    {
      if (ans.back() != a[i]) {
        ans.push_back(a[i]);
      }
        i++;
    }
    while(j<m)
    {
         if (ans.back() != b[j]) {
        ans.push_back(b[j]);
      }
        j++;
    }
    return ans;


}
