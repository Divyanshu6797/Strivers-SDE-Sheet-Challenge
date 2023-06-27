#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

/* void frotate(vector<int> &v,int n,int k)
{
    vector<int> temp(k);

    for(int i=0;i<k;i++)
    {
        temp[i]=v[i];
    }

    for(int i=k;i<n;i++)
    {
        v[i-k]=v[i];
    }
    int j=0;
    for(int i=n-k;i<n;i++)
    {
        v[i]=temp[j];
        j++;

    }


}
*/
// using 3 reverses
void frotate(vector<int> &v,int n,int k)
{
    
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    reverse(v.begin(),v.end());

   
}

int main() {
    int n;
    cin>>n;

    vector<int> input(n);

    for (int i = 0; i < n; i++)
{
    cin>>input[i];
}
    int k;
    cin>>k;

   // frotate(input,n,k);

    frotate(input,n,k);

    for(int i=0;i<n;i++)
    {
        cout<<input[i]<<" ";
    }
}
