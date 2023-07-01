#include <bits/stdc++.h> 

int part(vector<int> &arr,int left,int right)
{
    int pivot=arr[left];
    int i=left;
    int j=right;

    while(i<j)
    {
        while(arr[i]<=pivot && i<=right-1)
        {
            i++;
        }
        while(arr[j]>pivot && j>=left+1)
        {
            j--;
        }

        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[left],arr[j]);
    return j;
}

void qs(vector<int> &arr,int left,int right)
{
    if(left<right)
    {
        int partition=part(arr,left,right);

        qs(arr,left,partition-1);
        qs(arr,partition+1,right);
    }
}
vector<int> quickSort(vector<int> arr)
{
    qs(arr,0,arr.size()-1);
    return arr;
}
