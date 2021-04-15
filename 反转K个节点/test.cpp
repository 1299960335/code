class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)
        return head;
        ListNode*cur=head;
        ListNode*pre=nullptr;//用来进行头插
        ListNode*last=nullptr;//保存第K个节点
        ListNode*first=head;//每次头插后的下一个节点
        ListNode*nhead=new ListNode();//哨兵节点
        nhead->next=head;
        ListNode*kcl=nhead;//表示反转前的前一组的最后一个节点
        int num=k;
        while(cur!=nullptr){
            first=cur; //保存每组反转的第一个节点
            while(cur!=nullptr&&num){ //找到每组的结尾
               cur=cur->next;
               num--;
            }
            if(cur==nullptr&&num>0)//如果走到整个链表的结尾且后面的节点总数小于K时直接退出
            break;
            pre=first->next;
            last=first;
            while(pre!=nullptr&&pre!=cur){//每次插入时，将后一个节点拿出来进行头插
              last->next=pre->next; //因为头插后原来的第一个节点就成了最后一个节点
              pre->next=first; //所以每次需要进行保存最后一个节点
              kcl->next=pre; //然后一直进行头插，更新first和pre
              pre=last->next;
              first=kcl->next;
            }
            kcl=last;//反转完后将前一组最后一个节点进行更新
            num=k;//让cur继续往后走
        }
        return nhead->next;
    }
};
