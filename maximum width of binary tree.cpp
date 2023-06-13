#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL)
    return 0;
    queue<pair<TreeNode<int>*,int>> q;
    
    q.push(make_pair(root,0));
    map<int,int> m;
    int maxi=0;
    

    while(!q.empty())
    {
        pair<TreeNode<int>*,int> temp=q.front();
        q.pop();

        TreeNode<int>* frontnode=temp.first;
         int level=temp.second;

         m[level]++;

         maxi=max(maxi,m[level]);

         if(frontnode->left)
         q.push(make_pair(frontnode->left,level+1));

         if(frontnode->right)
         q.push(make_pair(frontnode->right,level+1));




    }
    return maxi;
    
}
