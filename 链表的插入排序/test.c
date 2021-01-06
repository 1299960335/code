typedef struct ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head){
     if(head==NULL||head->next==NULL){//如果为空或者只有一个元素，则直接返回
         return head;
     }
     ListNode* vhead=(ListNode*)malloc(sizeof(ListNode));//创建哨兵节点
     ListNode* cur=head->next;
     ListNode* pre=head;
      vhead->next=pre;//将第一个节点放置在哨兵节点后，当作一个有序的链表
      pre->next=NULL;
     while(cur){
         ListNode*next=cur->next;
         if(cur->val<pre->val){//若cur的值小于第一个有序链表节点的值，则进行头插
             cur->next=pre;//然后将有序链表的头进行更新
             vhead->next=cur;
             pre=cur;
             cur=next;
         }
         else {
             ListNode*prev=pre;
             while(pre){//循环有序链表，找出当cur的值小于有序链表的其中某个节点进行插入
                 if(cur->val<pre->val){
                     prev->next=cur;
                     cur->next=pre;
                     cur=next;
                     break;
                 }
                 prev=pre;
                 pre=pre->next;
             }
             if(pre==NULL){//当走到这里说明cur的值大于所有有序链表中的节点
                 prev->next=cur;//将这个节点进行尾插
                 cur->next=NULL;
                 cur=next;
             }
             pre=vhead->next;
         }
     }
     return pre;//返回有序链表的头
}