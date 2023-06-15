#include<bits/stdc++.h>
/* using dfs
void dfs(int i, int j,vector<vector<int>> &image,int oldColor, int newColor,vector<int> deltaR,vector<int> deltaC,int n,int m)
{
    image[i][j]=newColor;

    for(int q=0;q<4;q++)
    {
        int nrow=i+deltaR[q];
        int ncol=j+deltaC[q];

        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && image[nrow][ncol]==oldColor && image[nrow][ncol]!=newColor)
        {
            dfs(nrow,ncol,image,oldColor,newColor,deltaR,deltaC,n,m);
        }
    }



}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor=image[x][y];
    int n=image.size();
    int m=image[0].size();

    vector<int> deltaR={0,-1,0,1};
    vector<int> deltaC={-1,0,1,0};


  dfs(x,y,image,oldColor,newColor,deltaR,deltaC,n,m);
    return image;


}
*/



//using bfs

void bfs(int i, int j,vector<vector<int>> &image,int oldColor, int newColor,vector<int> deltaR,vector<int> deltaC,int n,int m)
{
    image[i][j]=newColor;

    queue<pair<int,int>> q;
    q.push(make_pair(i,j));

    while(!q.empty())
    {
        pair<int,int> temp=q.front();
        q.pop();
         

        int row=temp.first;
        int col=temp.second;
         image[row][col]=newColor;




    for(int w=0;w<4;w++)
    {
        int nrow=row+deltaR[w];
        int ncol=col+deltaC[w];

        if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
            image[nrow][ncol] == oldColor && image[nrow][ncol] != newColor) {
                image[nrow][ncol]=newColor;
                q.push(make_pair(nrow,ncol));
        }
    }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor=image[x][y];
    int n=image.size();
    int m=image[0].size();

    vector<int> deltaR={0,-1,0,1};
    vector<int> deltaC={-1,0,1,0};


  bfs(x,y,image,oldColor,newColor,deltaR,deltaC,n,m);
    return image;


}
