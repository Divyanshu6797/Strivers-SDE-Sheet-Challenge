vector<int> getTopView(TreeNode<int> *root) {
     queue<pair<TreeNode<int>*,int>> q;
     vector<int> v;
     q.push(make_pair(root,0));
     map<int,int> m;
     if(root==NULL)
     return v;

     while(!q.empty())
     {
         pair<TreeNode<int>*,int> temp=q.front();
         q.pop();
         TreeNode<int>* frontnode=temp.first;
         int hd=temp.second;

         if(m.find(hd)==m.end())
         {
             m.insert({hd,frontnode->val});
         }
         if(frontnode->left)
         q.push(make_pair(frontnode->left,hd-1));

         if(frontnode->right)
         q.push(make_pair(frontnode->right,hd+1));
     }
    
    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        v.push_back(itr->second);


    }
    return v;

}
