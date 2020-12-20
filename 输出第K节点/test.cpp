class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k==0||pListHead==NULL){
            return NULL;
        }
           ListNode*cur=pListHead;
           ListNode*pre=pListHead;
        while(k){
            if(cur!=NULL){
                cur=cur->next;
                k--;
            }
            else{
                return NULL;
            }
        }
        while(pre&&cur){
            cur=cur->next;
            pre=pre->next;
        }
        return pre;
    }
};