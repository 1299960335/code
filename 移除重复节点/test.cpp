typedef struct ListNode ListNode;
struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if(head==NULL)
    return NULL;
    ListNode*nhead=(ListNode*)malloc(sizeof(ListNode));
    ListNode*cur=head;
    ListNode*kcl=nhead;
    ListNode*ntail=nhead;
    ntail->next=cur;
    cur=cur->next;
    ntail=ntail->next;
    ntail->next=NULL;
    while(cur!=NULL){
        while(kcl!=NULL){
            if(kcl->val==cur->val){
                break;
            }
            else{
                kcl=kcl->next;
            }
        }
        if(kcl==NULL){
            ntail->next=cur;
            cur=cur->next;
            ntail=ntail->next;
            ntail->next=NULL;
            kcl=nhead->next;
        }
        else{
            kcl=nhead->next;
            cur=cur->next;
        }
    }
    return nhead->next;
}