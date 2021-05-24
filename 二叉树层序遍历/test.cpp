class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if(root==nullptr)
        return vv;
        //创建两个数组储存每一层的节点
        vector<TreeNode*> curV;
        vector<TreeNode*> next;

        curV.push_back(root);
        while(!(curV.empty())){
            vector<int> v;//用来存储每一层的数据
            for(auto e:curV){
                v.push_back(e->val);

                if(e->left)
                next.push_back(e->left);

                if(e->right)
                next.push_back(e->right);
            }
            vv.push_back(v);//将数据放入vv中
            curV.swap(next);//将两个数组进行交换
            next.clear();//清空下一层的节点
        }
        return vv;
    }
};