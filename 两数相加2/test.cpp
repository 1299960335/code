class Solution {
public:
    ListNode*add(int val,int &ret){
       ListNode*Node=new ListNode();
        if(val<10){
            Node->val=val;
            ret=0;
        }
        else{
            Node->val=val-10;
            ret=1;
        }
        return Node;
    }
    ListNode*revese(ListNode*head){
        ListNode*last=head;
        ListNode* nnhead=new ListNode();
        ListNode*kcl=nnhead;
        kcl->next=last;
        last=last->next;
        kcl=kcl->next;
        kcl->next=nullptr;
        ListNode*pre=last;
         while(last!=nullptr){
              last=last->next;
              pre->next=kcl;
              nnhead->next=pre;
              kcl=pre;
              pre=last;
        }
        return nnhead->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          if(l1==nullptr)
          return l2;
          if(l2==nullptr)
          return l1;
          stack<int> v1,v2;
          ListNode*cur=l1;
          ListNode*pre=l2;
          while(cur!=nullptr){
              v1.push(cur->val);
              cur=cur->next;
          }
          while(pre!=nullptr){
              v2.push(pre->val);
              pre=pre->next;
          }
          int ret=0;
          ListNode*nhead=new ListNode();
          ListNode*kcl=nhead;
          while(!(v1.empty())&&!(v2.empty())){
              int val=v1.top()+v2.top()+ret;
              kcl->next=add(val,ret);
              kcl=kcl->next;         
              v1.pop();
              v2.pop();  
          }
          if(!(v1.empty())){
               while(!(v1.empty())){
                   int val=v1.top()+ret;
                   kcl->next=add(val,ret);
                   kcl=kcl->next;
                   v1.pop();
               }
          }
          else if(!(v2.empty())){
                while(!(v2.empty())){
                    int val=v2.top()+ret;
                    kcl->next=add(val,ret);
                    kcl=kcl->next;
                    v2.pop();
                }
          }
          if(ret==1){
              ListNode*Node=new ListNode(1);
              kcl->next=Node;
          }
          nhead->next= revese(nhead->next);
          return nhead->next;
    }
};