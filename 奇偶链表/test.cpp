class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode*nhead1=new ListNode;
        ListNode*nhead2=new ListNode;
        if(head==nullptr||head->next==nullptr)
        return head;
        ListNode*cur=head;
        ListNode*pre=nhead1;
        ListNode*kcl=nhead2;
        int num=1;
        while(cur){
            if(num%2==1){
                pre->next=cur;
                cur=cur->next;
                pre=pre->next;
                pre->next=nullptr;
                num++;
            }
            else{
                kcl->next=cur;
                cur=cur->next;
                kcl=kcl->next;
                kcl->next=nullptr;
                num++;
            }
        }
        pre->next=nhead2->next;
        return nhead1->next;
    }
};