struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
   if(l1==NULL){    //链表1为空 返回链表2
       return l2;
   }
   else if(l2==NULL){//链表2为空 返回链表1
       return l1;
   }
   struct ListNode*head=NULL;
   struct ListNode*cur=l1;
   struct ListNode*per=l2;
   if(per->val<cur->val){  //判断链表的第一个元素
         head=per;         //若链表1第一个元素小于链表2，则将头节点设为链表1
         per=per->next;    //反之设为链表2
    }
    else{
        head=cur;
        cur=cur->next;
    }
   struct ListNode*Next=head;
   while(cur&&per){    //循环判断链表值的大小
       if(per->val<cur->val){  //比较链表的值，将小的链表进行尾插
          Next->next=per;    //并更新新链表的尾节点
          Next=per;
          per=per->next;
       }
       else{
          Next->next=cur;
          Next=cur;
          cur=cur->next;
       }
   }
     if(per==NULL){     //若某个链表为空，则将另一个链表进行尾插
       Next->next=cur;   
     }
     else if(cur==NULL){//若两个都为空，则直接返回头节点
       Next->next=per;
     }
     return head;//返回头节点
}