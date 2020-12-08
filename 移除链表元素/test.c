struct ListNode* removeElements(struct ListNode* head, int val){
          if(head==NULL){        //判断是否为空指针
              return NULL;
          }
          else if(head->next==NULL){   //链表中只有一个元素的状况
              if(head->val==val){
                  free(head);
                  head=NULL;
                  return head;
              }
              return head;
          }
          while(head->val==val){   //判断第一个链表是否为val值
              if(head->next!=NULL){//如果头指针后还有链表，赋予新的头指针
                head=head->next;  
              }
              else if(head->next==NULL){//如果头指针后没有，将头指针置空
                  head=NULL;
                  return head;
              }
          }
           struct ListNode*cur=head;
           struct ListNode*pre=head;
          while(cur!=NULL) {   //若走到最后一个链表，则停止循环
             while(cur->val!=val){ //判断当前链表的值是否与val相等
                  pre=cur;       
              cur=cur->next;
              if(cur==NULL){        //循环中如果到最后一个链表后，直接返回
                  return head;
              }
              }
             pre->next=cur->next;//若不相等，遍历后续链表
             cur=pre->next;
          }
           return head;
}