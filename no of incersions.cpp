#include <bits/stdc++.h> 

void merge(long long *arr, long long l, long long m,long long r,long long *count)
    {
         long long i=l;
         long long j=m+1;
         long long size=r-l+1;
         long long a[size];
         long long k=0;
         
         while(i<=m && j<=r)
         {
             if(arr[i]<=arr[j])
             {
                 a[k]=arr[i];
                 k++;
                 i++;
                 
             }
             else 
             {
                 a[k]=arr[j];
                 k++;
                 j++;
                 *count=*count+m-i+1;
                 
             }
             
             
         }
         
         while(i<=m)
             {
                 a[k]=arr[i];
                 i++;
                 k++;
             }
        while(j<=r)
             {
                 a[k]=arr[j];
                 j++;
                 k++;
             }
             
         
             
             long long q=l;
             for(long long w=0;w<size;w++)
             {
                 arr[q]=a[w];
                 q++;
             }
             
    }
    
    void mergeSort(long long *arr, long long l, long long r,long long *count)
    {
        if(l>=r)
        return;
       
        
        long long m=(l+r)/2;
        
        mergeSort(arr,l,m,count);
        mergeSort(arr,m+1,r,count);
        
        merge(arr,l,m,r,count);
    }
long long getInversions(long long *arr, int n){
    long long a=0;
    long long *count=&a;

   ;
    mergeSort(arr, 0,n-1,count);
    return *count;
   
    
}
