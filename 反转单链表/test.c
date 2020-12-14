struct ListNode* reverseList(struct ListNode* head){
            struct ListNode*newhead=NULL;
            struct ListNode*cur=head;
            struct ListNode*tail=head;
            if(head==NULL){
                return head;
            }
            while(cur){
                tail=cur->next;
                cur->next=newhead;
                newhead=cur;
                cur=tail;
            }
            return newhead;
}