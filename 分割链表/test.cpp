class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead==NULL){
            return NULL;
      }
        ListNode*head1=new ListNode(0);//哨兵节点
        ListNode*head2=new ListNode(0);//哨兵节点
        ListNode*pre=head1;
        ListNode*kcl=head2;
        while(pHead){
            if(pHead->val<x){//遍历链表，大于X的放在一个链表中，小于放在另外一个；
                pre->next=pHead;
                pre=pre->next;
            }
            else{
                kcl->next=pHead;
                kcl=kcl->next;
            }
            pHead=pHead->next;
        }
        kcl->next=NULL;//将大链表的尾设为空
        pre->next=head2->next;//链接两个链表
        return head1->next;
    }
};