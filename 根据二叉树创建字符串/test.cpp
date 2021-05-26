class Solution {
public:
    void _tree2str(TreeNode*root,string& s)
    {
      if(root==nullptr)
        return;
        
        s+=to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr)
        return ;

        s+='(';
        _tree2str(root->left,s);
        s+=')';

        if(root->right!=nullptr){
            s+='(';
            _tree2str(root->right,s);
            s+=')';
        }

    }
    string tree2str(TreeNode* root) {
        string s;
        _tree2str(root,s);        
        return s;
    }
};