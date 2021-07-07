class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)
        return nullptr;
        ListNode* nhead=new ListNode;
        ListNode* cur=nhead;
        ListNode* pre=nhead;
        ListNode* kcl=nhead;
        nhead->next=head;
        while(n--){
            pre=pre->next;
        }
        while(pre){
            kcl=cur;
            cur=cur->next;
            pre=pre->next;
        }
        kcl->next=cur->next;
        return nhead->next;
    }
};