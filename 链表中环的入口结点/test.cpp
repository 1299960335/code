class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* cur = pHead;
        ListNode* pre = pHead;
        if(pHead == nullptr || pHead->next == nullptr ){
            return nullptr;
        }
        while(cur != nullptr && cur->next!=nullptr){
            cur = cur->next->next;
            pre = pre->next;
            if(cur == pre){
                break;
            }
        }
        if(cur == nullptr || cur->next == nullptr){
            return nullptr;
        }
        else{
            cur = pHead;
            while(pre != cur){
                pre = pre->next;
                cur = cur->next;
            }
            return pre;
        }
    }
};