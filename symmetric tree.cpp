/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool issym(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if((root1==NULL && root2==NULL)  )
    {
        return true;
    }
    

    if(root1->data!=root2->data )
    return false;
    issym(root1->left,root2->right);
    
    

}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return true;
    }
    BinaryTreeNode<int>* root1=root;
   return issym(root,root1);

}
