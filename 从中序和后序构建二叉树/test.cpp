class Solution {
public:
    TreeNode* _buildTree(vector<int>&postorder,vector<int>&inorder,
    int previ,int inbegin,int inend){
        if(previ<0)
               return nullptr;

        //中间节点不存在
        if(inbegin>inend)
        return nullptr;

        //确定根在中序的位置，分割出左右子树
        TreeNode*root =new TreeNode(postorder[previ]);
        int rooti=inbegin;
        while(rooti<=inend){
            if(inorder[rooti]==postorder[previ])
                break;
            else
                rooti++;
        }

        --previ;
        //previ-inend+rooti是为了构建左子树，后序的左子树在最前
        root->left=_buildTree(postorder,inorder,previ-inend+rooti,inbegin,rooti-1);
        root->right=_buildTree(postorder,inorder,previ,rooti+1,inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int previ=postorder.size()-1;
        return _buildTree(postorder,inorder,previ,0,postorder.size()-1);
    }
};