vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int,vector<int>>m;
    vector<int> v;
    if(root==NULL)
    return v;

    queue<pair<TreeNode<int>*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
         
         pair<TreeNode<int>*,int> temp=q.front();
         q.pop();

         TreeNode<int>* frontnode=temp.first;
         int hd=temp.second;

         m[hd].push_back(frontnode->data);

         if(frontnode->left)
         q.push(make_pair(frontnode->left,hd-1));

         if(frontnode->right)
         q.push(make_pair(frontnode->right,hd+1));

        

    }
    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        for(int i=0;i<m[itr->first].size();i++)

        {
            v.push_back(m[itr->first][i]);
        }
    }
    return v;
}
