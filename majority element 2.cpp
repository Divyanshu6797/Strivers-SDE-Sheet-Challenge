#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n=arr.size();
    int m=floor(n/3);


   vector<int>v;
   int cnt1=0;
   int cnt2=0;
   int el1=INT_MIN;
   int el2=INT_MIN;

   for(int i=0;i<n;i++)
   {
       if(cnt1==0 && arr[i]!=el2)
       {
           cnt1++;
           el1=arr[i];
       }
       else if (cnt2==0 && arr[i]!=el1)
       {
           cnt2++;
           el2=arr[i];
       }
       else if (arr[i]==el1)
       {
           cnt1++;
       }
       else if(arr[i]==el2)
       {
           cnt2++;
       }
       else
       {
           cnt1--;
           cnt2--;
       }
   }
   int c1=0;
   int c2=0;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==el1)
       c1++;

        else if(arr[i]==el2)
        c2++;
   }
   if(c1>m)
   v.push_back(el1);

   if(c2>m)
   v.push_back(el2);

   
   return v;


   

}
