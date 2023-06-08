bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size();
    int n=mat[0].size();
    int i=m-1;
    int j=0;

    while(i>=0 && j<n)
    {
        if(mat[i][j]==target)
        return true;

        if(target>mat[i][j])
        {
            j++;
        }
        else if(target<mat[i][j])
        {
            i--;
        }
    }
    return false;
        
}
