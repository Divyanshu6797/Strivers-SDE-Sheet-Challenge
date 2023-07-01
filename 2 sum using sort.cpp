#include<bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    
    sort(book.begin(),book.end());

    int left=0;
    int right=n-1;

    int sum=book[left]+book[right];

    while(left<right)
    {
        if(sum==target)
        return "YES";

        else if(sum<target)
        {
            sum-=book[left];
            left++;
            sum+=book[left];
        }
        else{
            sum-=book[right];
            right--;
            sum+=book[right];
        }
        


    }
    return "NO";
}
