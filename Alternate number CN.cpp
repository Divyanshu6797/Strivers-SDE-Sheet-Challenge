vector<int> alternateNumbers(vector<int>&a) {
    int n=a.size();

    vector<int> ans(n);

    int neg=1;
    int pos=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            ans[neg]=a[i];
            neg+=2;

        }
        else{
            ans[pos]=a[i];
            pos+=2;
        }
    }
    return ans;
}
