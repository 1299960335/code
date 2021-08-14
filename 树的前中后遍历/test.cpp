class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void first(vector<int> &v,TreeNode*root){
        if(root==nullptr){
            return;
        }
        v.push_back(root->val);
        first(v,root->left);
        first(v,root->right);
    }
    void mid(vector<int> &v,TreeNode*root){
        if(root==nullptr)
            return;
        mid(v,root->left);
        v.push_back(root->val);
        mid(v,root->right);
    }
    void last(vector<int> &v,TreeNode*root){
        if(root==nullptr)
            return;
        last(v,root->left);
        last(v,root->right);
        v.push_back(root->val);
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> v1;
        v1.resize(3);
        first(v1[0],root);
        mid(v1[1],root);
        last(v1[2],root);
        return v1;
    }
};