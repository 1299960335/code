typedef struct ListNode ListNode;
void deleteNode(struct ListNode* node) {
      ListNode*next=node->next;
      node->val=node->next->val;
      node->next=node->next->next;
      free(next);
      next=NULL;
}