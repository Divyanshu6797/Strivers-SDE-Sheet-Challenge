#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int maxsum(TreeNode<int> *root,long long int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    long long int start=0;
    long long int end=0;
    long long int left=max(maxsum(root->left,maxi),start);
    long long int right=max(maxsum(root->right,maxi),end);
    maxi=max(maxi,left+right+root->val);

    return max(left,right)+root->val;
    

}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==NULL || root->left==NULL || root->right==NULL )
    {
        return -1;
    }

    long long int maxi=INT_MIN;
    maxsum(root,maxi);
    return maxi;

    
}
