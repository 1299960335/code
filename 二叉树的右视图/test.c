void rightSize(struct TreeNode* root,int*arr,int Depth,int*returnSize){
    if(root==NULL)
    return;
    if(Depth>(*returnSize)){
        arr[*returnSize]=root->val;
        *returnSize=Depth;
    }
    rightSize(root->right,arr,Depth+1,returnSize);
    rightSize(root->left,arr,Depth+1,returnSize);
}
int* rightSideView(struct TreeNode* root, int* returnSize){
     *returnSize=0;
     int Depth=1;
     int*arr=(int*)malloc(sizeof(int)*1000);
     rightSize(root,arr,Depth,returnSize);
     return arr;
}