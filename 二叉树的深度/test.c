int maxDepth(struct TreeNode* root){
   if(root == NULL)
      return 0;
    int leftDepth = maxDepth(root->left);//左子树的深度
    int rightDepth = maxDepth(root->right);//右子树的深度
    return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;//最大子树深度加上根的深度
   
}