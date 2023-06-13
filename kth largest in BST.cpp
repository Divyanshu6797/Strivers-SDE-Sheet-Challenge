#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

    void inorderreverse(TreeNode<int> *root, int &k,int &target)
{
    if(root==NULL)
    return;

    inorderreverse(root->right,k,target);
    k--;
    if(k==0)
    {
        target=root->data; 
        k=k-1;
        return ;
    }
    

    inorderreverse(root->left,k,target);



}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.

    int target=-1;
    int b=k;
     inorderreverse(root,b,target);
     return target;
}
