int  TreeDepth(struct TreeNode* root)//计算深度
{
    if(root == NULL)
        return 0;
    
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);

    return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
}

bool isBalanced(struct TreeNode* root){
    if(root==NULL)
       return true;
    int gap=TreeDepth(root->left)-TreeDepth(root->right);//计算左右孩子深度的差值
    if(abs(gap)>1)
       return false;
    return isBalanced(root->left)&&isBalanced(root->right);
}