class Solution {
public:
    bool isPalindrome(ListNode* head) {
         if(head==nullptr||head->next==nullptr)
         return true;
        ListNode*fast=head;
        ListNode*last=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            last=last->next;
            fast=fast->next->next;
        }
        ListNode* nhead=new ListNode();
        ListNode*cur=nhead;
        cur->next=last;
        last=last->next;
        cur=cur->next;
        cur->next=nullptr;
        ListNode*pre=last;
        while(last!=nullptr){
              last=last->next;
              pre->next=cur;
              nhead->next=pre;
              cur=pre;
              pre=last;
        }
        cur=nhead->next;
        fast=head;
        while(cur!=nullptr){
            if(cur->val!=fast->val){
                return false;
            }
            cur=cur->next;
            fast=fast->next;
        }
        return true;
    }
};