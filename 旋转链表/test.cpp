class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*cur=head;
        ListNode*pre=head;
        int num=0;
        while(cur){
            pre=cur;
            cur=cur->next;
            num++;
        }
        k=k%num;
        if(k==0)
        return head;
        pre->next=head;
        num=num-k;
        cur=head;
        while(num--){
            cur=cur->next;
        }
        ListNode*nhead=new ListNode;
        nhead->next=cur;
        pre=cur->next;
        ListNode*kcl=pre;
        while(pre!=cur){
            kcl=pre;
            pre=pre->next;
        }
        kcl->next=nullptr;
        return nhead->next;
    }
};