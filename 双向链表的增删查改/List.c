#include"List.h"
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) {
		printf("内存不足");
		exit(-1);
	}
	head->_next = head;
	head->_prev = head;
	return head;
}
//创建新节点
ListNode* List(LTDataType x)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		printf("内存不足");
		exit(-1);
	}
	new_node->_data = x;
	new_node->_next = NULL;
	new_node->_prev = NULL;
	return new_node;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	if (pHead->_next == pHead) {
		free(pHead);
		pHead = NULL;
	}
	ListNode* head = pHead->_next;
	while (head!=pHead) {
		ListNode* next = head;
		head = head->_next;
		free(next);
		next = NULL;
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* head = pHead->_next;
	while (head != pHead) {
		printf("%d ", head->_data);
		head = head->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* new_node = List(x);
	ListNode* tail = pHead->_prev;
	tail->_next = new_node;
	pHead->_prev = new_node;
	new_node->_next = pHead;
	new_node->_prev = tail;
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (pHead->_next == pHead) {
		exit(-1);
	}
	else {
		ListNode* tail = pHead->_prev;
		pHead->_prev = tail->_prev;
		tail->_prev->_next = pHead;//尾节点的前一个节点的next指向头
		free(tail);
		tail = NULL;
	}
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* new_node = List(x);
	ListNode* first = pHead->_next;
	new_node->_next = first;
	new_node->_prev = pHead;
	first->_prev = new_node;
	pHead->_next = new_node;
}
// 双向链表头删
void ListPopFront(ListNode* pHead) 
{
	ListNode* first = pHead->_next;
	pHead->_next = first->_next;
	first->_next->_prev = pHead;//头节点的下一个节点的prev指向哨兵节点
	free(first);
	first = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	if (pHead->_next == pHead) {
		return NULL;
	}
	ListNode* head = pHead->_next;
	while (head != pHead) {
		if (head->_data == x) {
			return head;
		}
		head = head->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* first = pos->_prev;
	ListNode* new_node = List(x);
	new_node->_prev = first;
	new_node->_next = pos;
	first->_next = new_node;
	pos->_prev = new_node;
	
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* Node1 = pos->_prev;//pos的前一个节点
	ListNode* Node2 = pos->_next;//pos的后一个节点
	Node1->_next = pos->_next;
	Node2->_prev = pos->_prev;
	free(pos);
	pos = NULL;
}