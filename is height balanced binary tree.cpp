#include <bits/stdc++.h> 
using namespace std;
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
pair<bool,int> balancedBT(BinaryTreeNode<int>*root){
    if(root==NULL)
    {
        pair<bool,int> temp=make_pair(true,0);
        return temp;
        
    }
    pair<bool,int> leftchild=balancedBT(root->left);
    pair<bool,int> rightchild=balancedBT(root->right);

    bool left=leftchild.first;
    bool right=rightchild.first;

    int leftheight=leftchild.second;
    int rightheight=rightchild.second;
    int diff=abs(leftheight-rightheight);

    if(diff <=1 && left && right)
    {
        pair<bool,int> temp=make_pair(true,max(leftheight,rightheight)+1);
        return temp;

    }
    else
    {
        pair<bool,int> temp=make_pair(false,max(leftheight,rightheight)+1);
        return temp;

    }


}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    pair<bool,int> m=balancedBT(root);
    return m.first;
}
