class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode*nhead=(ListNode*)malloc(sizeof(ListNode));
        ListNode*cur=head;
        ListNode*pre=nhead;
        pre->next=cur;
        cur=cur->next;
        pre=pre->next;
        pre->next=NULL;
        while(cur){
            if(pre->val!=cur->val){
                pre->next=cur;
                cur=cur->next;
                pre=pre->next;
                pre->next=NULL;
            }
            else{
                cur=cur->next;
            }
        }
        return nhead->next;
    }
};