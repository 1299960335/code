 void Ergodic(struct TreeNode* root,int*a,int*returnSize)
 {
    if(root==NULL)//遇到空返回
       return ;    
    int size=*returnSize;
    Ergodic(root->left,a,&size);//递归放左子树的值  
    a[size]=root->val;//将值放进数组中
    size++;
    Ergodic(root->right,a,&size);//递归放右子树的值
    *returnSize=size;
 }
int* inorderTraversal(struct TreeNode* root, int* returnSize){
      *returnSize=0;
      if(root==NULL){
           return NULL;
      }
        int *arr=(int*)malloc(sizeof(int)*100);//创建一个数组
         Ergodic(root,arr,returnSize);
         return arr;
}