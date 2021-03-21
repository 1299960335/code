typedef struct ListNode ListNode;
int kthToLast(struct ListNode* head, int k){
    if(head==NULL)
    return 0;
    if(k==0)
    return 0;
    ListNode*fast=head;
    ListNode*slow=head;
    while(k){
        fast=fast->next;
        k--;
    }
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    return slow->val;
}