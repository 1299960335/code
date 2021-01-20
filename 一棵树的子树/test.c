bool isSametree(struct TreeNode*s,struct TreeNode*t){//比较子树是否相同
    if(s==NULL&&t==NULL)
        return true;
    if(s==NULL&&t!=NULL)
        return false;
    if(s!=NULL&&t==NULL)
        return false;
    if(s->val!=t->val)
        return false;   
    return isSametree(s->left,t->left)&&isSametree(s->right,t->right);    
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
      if(s==NULL)//若S树为空，直接返回false
          return false;
      if(isSametree(s,t))
           return true;
      return isSubtree(s->left,t)||isSubtree(s->right,t);
}