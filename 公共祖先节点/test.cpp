class Solution {
public:
    bool FindPath(TreeNode* root,TreeNode*x,stack<TreeNode*>& path)
    {
        if(root==nullptr)
        return false;

        path.push(root);
        if(root==x)
        return true;

        if(FindPath(root->left,x,path))
        return true;

        if(FindPath(root->right,x,path))
        return true;

        //root 左树 root右数，都没有x节点
        //说明root不会是路径中的一个点,将节点弹出
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       stack<TreeNode*> pPtah;
       stack<TreeNode*> qPtah;

       FindPath(root,p,pPtah);
       FindPath(root,q,qPtah);

       //将两个栈等长再进行比较
       while(pPtah.size()>qPtah.size()){
           pPtah.pop();
       }
       while(pPtah.size()<qPtah.size()){
           qPtah.pop();
       }
       while(pPtah.top()!=qPtah.top()){
           pPtah.pop();
           qPtah.pop();
       }
       return pPtah.top();

    }
};