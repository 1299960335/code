struct ListNode* (struct ListNode* head, int x)
{
	assert(head);
	assert(head->prev != head);
	struct ListNode* cur = head->prev;
	struct ListNode* curPrev = cur->prev;
	head->prev = curPrev;
	curPrev->next = head;
	free(cur);
}