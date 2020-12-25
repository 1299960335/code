class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
       if(A==NULL||A->next==NULL){//如果链表为空 或者只有一个节点，则返回false
           return false;
       }
        ListNode* cur=A;
        ListNode* pre=A;
        while(pre==NULL&&pre->next==NULL){//找到链表的中间节点
            cur=cur->next;
            pre=pre->next->next;
        }
        ListNode*next=NULL;
        pre=NULL;
        while(cur){//将中间节点后的链表反转
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        while(A){    //比较反转后的节点与初始的值是否相等
            if(pre->val!=A->val){ //不相等返回false
                return false;
            }
            cur=cur->next;
            A=A->next;
        }
        return true;