#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void left(TreeNode<int>* root,vector<int> &v )
{
   if((root==NULL) || (root->left==NULL && root->right==NULL))
    return;

    v.push_back(root->data);

    if(root->left)
    left(root->left,v);
    else 
    left(root->right,v);


}
void leaves(TreeNode<int>* root,vector<int>&v)
{
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
    {
        v.push_back(root->data);
        return;

    }
    

    

    
    leaves(root->left,v);
    
    leaves(root->right,v);

}
void right(TreeNode<int>* root,vector<int>&v)
{
   if((root==NULL) || (root->left==NULL && root->right==NULL))
    return;

   

    if(root->right)
    right(root->right,v);
    else 
    right(root->left,v);

     v.push_back(root->data);


}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> v;
    if(root==NULL)
    return v;
    v.push_back(root->data);

    left(root->left,v);
    leaves(root->left,v);
    leaves(root->right,v);
    right(root->right,v);

   

    return v;
}
