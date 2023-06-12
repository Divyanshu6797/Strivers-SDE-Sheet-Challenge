#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void inorder(BinaryTreeNode<int> *root,vector<int>&v)
{
    if(root==NULL)
    return;
    
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
void preorder(BinaryTreeNode<int> *root,vector<int>&v)
{
    if(root==NULL)
    return;
    v.push_back(root->data);
    preorder(root->left,v);
    preorder(root->right,v);
}

void postorder(BinaryTreeNode<int> *root,vector<int>&v)
{
    if(root==NULL)
    return;
    
    postorder(root->left,v);
    postorder(root->right,v);
    v.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> v1;
    inorder(root,v1);

    vector<int>v2;
    preorder(root,v2);

    vector<int>v3;
    postorder(root,v3);

    vector<vector<int>> v;
     v.push_back(v1);
     v.push_back(v2);
     v.push_back(v3);

     return v;

}
