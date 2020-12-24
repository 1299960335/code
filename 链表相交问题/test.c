struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
         if(headA==NULL||headB==NULL){    //若其中一个链表为空，则直接返回
            return NULL;
        }
      struct ListNode *cur=headA;
      struct ListNode *pre=headB;
      while(cur!=pre){    //若两个链表地址不同进行循环，若不相等则继续
          if(cur==NULL){   //当A链表走完后，将B链表链接在后面，用来保证总链表的长度相等
              cur=headB;
          }
          else if(pre==NULL){//同理
            pre=headA;
          }
         if(pre==cur){     //判断地址是否相等，用来防止将链表合并后，头节点相等不能识别的情况
              return cur;
          }
            cur=cur->next;
            pre=pre->next;
      }
    return cur;
}