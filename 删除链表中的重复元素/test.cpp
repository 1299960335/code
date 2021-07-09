class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(head==nullptr||head->next==nullptr)
       return head;
       ListNode*nhead=new ListNode;
       ListNode*cur=nhead;
       ListNode*pre=nhead;
       cur->next=head;
       while(cur->next&&cur->next->next){
           if(cur->next->val==cur->next->next->val){
               int x=cur->next->val;
               while(cur->next&&cur->next->val==x){
                   cur->next=cur->next->next;
               }
           }
           else{
               cur=cur->next;
           }
       }
       return nhead->next;
    }
};