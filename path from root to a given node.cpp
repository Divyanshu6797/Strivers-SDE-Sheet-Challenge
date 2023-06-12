

bool path(TreeNode<int> *root,int x,vector<int> &v)
{
  if (root == NULL) {
	 return false;
  }

        v.push_back(root->data);

	bool left=path(root->left,x,v);
	bool right=path(root->right,x,v);

   
	if(left || right || root->data==x) 
		return true;
	

	if(left==false && right==false)
	{
		v.pop_back();
		return false;
	}

    




}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> v;
	

    path(root,x,v);
	return v;
}
