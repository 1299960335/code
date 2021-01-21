bool isSameTree(struct TreeNode* p, struct TreeNode* q){
     if(p==NULL&&q==NULL)//如果都为空，返回true
       return true;
     if(p==NULL&&q!=NULL)//如果一个为空一个不为空，返回false
       return false;
     if(p!=NULL&&q==NULL)
       return false;
     if(p->val!=q->val)//如果值不相等返回false
       return false;
     return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}