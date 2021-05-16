class Solution {
public:
    void _Converet(TreeNode* cur,TreeNode*& prev){
        if(cur==nullptr)
            return;
        
        _Converet(cur->left,prev);
        
        cur->left=prev;
        if(prev){
            prev->right=cur;
        }
        prev=cur;
        
        _Converet(cur->right,prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev=nullptr;
        if(pRootOfTree==nullptr)
            return nullptr;
        _Converet(pRootOfTree,prev);
        
        TreeNode*head=pRootOfTree;
        while(head->left){
            head=head->left;
        }
        return head;
    }
};