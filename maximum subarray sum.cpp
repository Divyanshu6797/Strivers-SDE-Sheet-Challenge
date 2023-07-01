#include <bits/stdc++.h> 

//kadane's algo
long long maxSubarraySum(int arr[], int n)
{
    long long sum=0;
    long long maxi=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        maxi=max(sum,maxi);

        if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;


    
}
