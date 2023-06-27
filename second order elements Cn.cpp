#include<bits/stdc++.h>
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int largest=a[0];
    int secondLargest;
    int smallest=a[0];
    int secondSmallest=INT_MAX;

    for(int i=1;i<n;i++)
    {
        if(a[i]>largest)
        {
            secondLargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>secondLargest)
        {
            secondLargest=a[i];
        }

        if(a[i]<smallest)
        {
            secondSmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]>smallest && secondSmallest>a[i])
        {
            secondSmallest=a[i];
        }

    }
    vector<int> ans;
    ans.push_back(secondLargest);
    ans.push_back(secondSmallest);

    return ans;
}
