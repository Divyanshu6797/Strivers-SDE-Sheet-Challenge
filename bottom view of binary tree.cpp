vector<int> bottomView(BinaryTreeNode<int> * root)
{
    
    map<int,int> m;
    vector<int> v;

    if(root==NULL)
    return v;

    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push(make_pair(root,0));

    while (!q.empty()) {

      pair<BinaryTreeNode<int> *, int> temp = q.front();
      q.pop();

      BinaryTreeNode<int> *frontnode = temp.first;
      int hd = temp.second;

      m[hd] = frontnode->data;

      if (frontnode->left)
        q.push(make_pair(frontnode->left, hd - 1));

      if (frontnode->right)
        q.push(make_pair(frontnode->right, hd + 1));
    }
    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        v.push_back(itr->second);
    }
    return v;

}
