void inorder(TreeNode<int> *root, int &k,int &target)
{
    if(root==NULL)
    return;

    inorder(root->left,k,target);
    k--;
    if(k==0)
    {
        target=root->data; 
        k=k-1;
        return ;
    }
    

    inorder(root->right,k,target);


}

int kthSmallest(TreeNode<int> *root, int k)
{

   
    int target;
    int b=k;
     inorder(root,b,target);
     return target;
}
