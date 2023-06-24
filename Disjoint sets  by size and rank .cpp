#include<bits/stdc++.h>
using namespace std;

// one based indexing graph

class DisjointSet
{
    vector<int> parent, rank,size;
    public :

    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }

    }
    int getUparent(int node)                     
    {
        if(parent[node]==node)
        return node;
        else  
         return  parent[node]=getUparent(parent[node]);                //path compression
    }

    void unionByRank(int u,int v)
    {
        int up_u=getUparent(u);
        int up_v=getUparent(v);

        if(rank[up_u]==rank[up_v])
        {
            parent[up_u]=up_v;
            rank[up_v]++;
        }
        else if(rank[up_u]<rank[up_v])
        {
            parent[up_u]=up_v;


        }
        else{
            parent[up_v]=up_u;
        }


    }
    void unionBySize(int u,int v)
    {
        int up_u=getUparent(u);
        int up_v=getUparent(v);

        if(up_u==up_v)
        return;
        
        if(size[up_u]<size[up_v])
        {
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }

        }
    





};

int main()
{
 /*   DisjointSet ds(7);

    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank (5,6);

    if(ds.getUparent(3)==ds.getUparent(7))
    {
        cout<<1;
    }
    else 
    cout<<0;

    cout<<endl;

    ds.unionByRank (3,7);

     if(ds.getUparent(3)==ds.getUparent(7))
    {
        cout<<1;
    }
    else 
    cout<<0;
    */

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.getUparent(3) == ds.getUparent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.getUparent(3) == ds.getUparent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
    

}
