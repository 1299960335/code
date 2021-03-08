struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head==NULL)
    return NULL;
    if(head->val==val){
        head=head->next;
        return head;
    }
    struct ListNode*cur=head->next;
    struct ListNode*pre=head;
    while(cur!=NULL){
        if((cur->val)==val){
            pre->next=cur->next;
            break;
        }
        else{
            pre=cur;
            cur=cur->next;
        }
    }
    return head;
}