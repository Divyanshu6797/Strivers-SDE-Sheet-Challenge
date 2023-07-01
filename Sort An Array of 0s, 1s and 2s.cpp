#include <bits/stdc++.h> 

//Deutch flag algorithm
void sortArray(vector<int>& arr, int n)
{
    
    int left=0;
    int mid=0;
    int high=n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[left]);
            mid++;
            left++;


        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
