 #include<bits/stdc++.h>
 using namespace std;
 
 int largestRectangle(vector < int > & heights) {
   int n=heights.size();
   int nextSmall[n];
   int prevSmall[n];

   // next small
   stack<int> stk;
   stk.push(-1);
   for(int i=n-1;i>=0;i--)
   {
     while(stk.top()!=-1 && heights[stk.top()]>=heights[i])
     {
       stk.pop();
     }
     nextSmall[i]=stk.top();
     stk.push(i);


   }
   // prev small
    stack<int> st;
    st.push(-1);
   for(int i=0;i<n;i++)
   {
     while(st.top()!=-1 && heights[st.top()]>=heights[i])
     {
       st.pop();
     }
     prevSmall[i]=st.top();
     st.push(i);

   }

   for(int i=0;i<n;i++)
   {
     if(nextSmall[i]==-1)
     nextSmall[i]=n;
   }
   int maxi= INT_MIN;

   for(int i=0;i<n;i++)
   {
     int area=heights[i]*(nextSmall[i]-prevSmall[i]-1);
     maxi=max(maxi,area);

   }
   return maxi;


 }
