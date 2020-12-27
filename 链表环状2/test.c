struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL){  //判断是否为空链表
        return NULL;
    }
    struct ListNode*cur=head;
    struct ListNode*pre=head;
    while(pre&&pre->next){  //判断链表是否有环
        cur=cur->next;
        pre=pre->next->next;
        if(cur==pre){
            break;
        }
    }
    if(pre==NULL||pre->next==NULL){  //判断链表为一个元素时的情况
        return NULL;
    }
    while(pre){       //从环状相遇点开始进行循环，
        if(pre==head){
            return pre;
        }
        pre=pre->next;
        head=head->next;
    }
    return NULL;
}