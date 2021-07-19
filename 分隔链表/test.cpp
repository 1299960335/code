class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int num=0;
        ListNode*cur=head;
        while(cur){
            num++;
            cur=cur->next;
        }
        int size=num%k;
        int size2=num/k;
        num/=k;
        cur=head;
        ListNode*pre=head;
        while(k){
            if(size>0){
                num+=1;
            }
            while(cur&&--num){
                cur=cur->next;
            }
            if(cur==nullptr){
                v.push_back(pre);
                pre=nullptr;
            }
            else{
                ListNode*kcl=pre;
                v.push_back(kcl);
                pre=cur->next;
                cur->next=nullptr;
                cur=pre;
                size--;
                num=size2;   
            }
            k--;
        }
        return v;
    }
};