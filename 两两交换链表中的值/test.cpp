class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*nhead=new ListNode;
        nhead->next=head;
        ListNode*cur=head;
        ListNode*kcl=nhead;
        ListNode*pre=head->next;
        while(pre){
            kcl->next=pre;
            cur->next=pre->next;
            pre->next=cur;
            kcl=cur;
            cur=cur->next;
            if(cur==nullptr)
            break;
            pre=cur->next;
        }
        return nhead->next;
    }
};