class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
        return l2;
        if(l2==nullptr)
        return l1;
        ListNode*nhead=new ListNode();
        ListNode*cur=l1;
        ListNode*pre=l2;
        ListNode*kcl=nullptr;
        ListNode*tail=nhead;
        while(cur!=nullptr&&pre!=nullptr)
        {
            if(cur->val>pre->val){
                kcl=pre;
                pre=pre->next;
                tail->next=kcl;
                kcl->next=nullptr;
                tail=tail->next;
            }
            else{
                kcl=cur;
                cur=cur->next;
                tail->next=kcl;
                kcl->next=nullptr;
                tail=tail->next;
            }
        }
        if(cur!=nullptr)
        tail->next=cur;
        else if(pre!=nullptr)
        tail->next=pre;
        return nhead->next;
    }
};