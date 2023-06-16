#include<bits/stdc++.h>
using namespace std;

// O(n X m) + log(no of values in set/ at ma n X M) O(n X m X 4)
void dfs(int **arr,int i,int j,int row,int col,vector<pair<int,int>> &ans,vector<vector<int>> &vis,int delrow[],int delcol[],int n,int m)
{
    vis[i][j]=1;
    ans.push_back(make_pair(row-i,col-j));
   

    for(int w=0;w<4;w++)
    {
        int nrow=i+delrow[w];
        int ncol=j+delcol[w];

        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && arr[nrow][ncol]==1)
        {
            dfs(arr,nrow,ncol,row,col,ans,vis,delrow,delcol,n,m);
        }
    }



}

int distinctIslands(int** arr, int n, int m)
{
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st;

    int delrow[]={-1,0,+1,0};
    int delcol[]={0,-1,0,+1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && arr[i][j]==1)
            {
                vector<pair<int,int>> ans;
                dfs(arr,i,j,i,j,ans,vis,delrow,delcol,n,m);
                st.insert(ans);
            }


        }
    }
    return st.size();

    
}
