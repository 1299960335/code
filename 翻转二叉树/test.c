struct TreeNode* invertTree(struct TreeNode* root){
	if (root == NULL) {
		return NULL;
	}
	struct TreeNode* temp = root->left;//翻转左右子树
	root->left = root->right;
	root->right = temp;
	invertTree(root->left);
	invertTree(root->right);
    return root;
}