#include"SList.h"
SListNode* BuySListNode(SLTDateType x)// 动态申请一个节点
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode*));
	if (newNode == NULL) {
		printf("申请失败");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void SListPrint(SListNode* plist)// 单链表打印
{
	while (plist != NULL) {
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL");
	printf("\n");
}
void SListPushBack(SListNode** pplist, SLTDateType x)// 单链表尾插
{
	if (*pplist == NULL) {
		*pplist = BuySListNode(x);
	}
	else {
		SListNode* cur = *pplist;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = BuySListNode(x);
	}
}
void SListPushFront(SListNode** pplist, SLTDateType x)// 单链表的头插
{
		SListNode* cur = *pplist;
		*pplist = BuySListNode(x);
		(*pplist)->next = cur;
}
void SListPopBack(SListNode** pplist)// 单链表的尾删
{
	if (*pplist == NULL) {
		return;
	}
	else if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* pre = NULL;
		SListNode* cur = *pplist;
		while (cur->next != NULL) {
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		pre->next = NULL;
	}
}
void SListPopFront(SListNode** pplist) // 单链表头删
{
	if (*pplist == NULL) {
		return;
	}
	else {
		SListNode* cur = (*pplist)->next;
		free(*pplist);
		*pplist = cur;
	}
}
SListNode* SListFind(SListNode* plist, SLTDateType x)//在pos插入
{
	assert(plist);
	SListNode* cur = plist;
	while (cur->data!=x) {
		cur = cur->next;
		if (cur == NULL) {
			return NULL;
		}
	}
	return cur;
}
void SListInsertAfter(SListNode* pos, SLTDateType x)//在pos位置删除
{
	assert(pos);
	SListNode* cur = BuySListNode(x);
	cur->next = pos->next;
	pos->next = cur;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
}