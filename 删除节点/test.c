struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
bool removeNode(ListNode* pNode) {
if(pNode==NULL||pNode->next==NULL){
return false;
}
pNode->next=NULL;
pNode->val=0;
free(pNode);
pNode=NULL;
return true;
}