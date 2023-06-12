void leftview(TreeNode<int>* root,int level, map<int,int> &m)
{
    if(root==NULL)
    return;

    if(m.find(level)==m.end())
    {
        m.insert({level,root->data});
        
    }
    leftview(root->left,level+1,m);
    leftview(root->right,level+1,m);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    map<int,int> m;
    int level=0;
    leftview(root,level,m);
    

    vector<int> v;
    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        v.push_back(itr->second);


    }
    return v;
}
