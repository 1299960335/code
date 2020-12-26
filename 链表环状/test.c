bool hasCycle(struct ListNode *head) {
    if(head==NULL){    //如果头指针为空，返回false
        return false;
    }
    struct ListNode* cur=head;   //慢指针
    struct ListNode*pre=head;    //快指针
    while(pre&&pre->next){  //当快指针走到空，则推出循环
         cur=cur->next;
         pre=pre->next->next;
        if(pre==cur){  //当两个指针地址相同时，则表明有环
        return true;
        }
    }
    return false;//若退出循环，则表示没有环
}