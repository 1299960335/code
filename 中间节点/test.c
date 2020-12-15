struct ListNode* middleNode(struct ListNode* head){
        struct ListNode* slow=head;
        struct ListNode* fast=head;
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            return head;
        }
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}