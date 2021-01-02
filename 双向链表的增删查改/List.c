#include"List.h"
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) {
		printf("�ڴ治��");
		exit(-1);
	}
	head->_next = head;
	head->_prev = head;
	return head;
}
//�����½ڵ�
ListNode* List(LTDataType x)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		printf("�ڴ治��");
		exit(-1);
	}
	new_node->_data = x;
	new_node->_next = NULL;
	new_node->_prev = NULL;
	return new_node;
}
// ˫����������
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
// ˫�������ӡ
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
// ˫������β��
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
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (pHead->_next == pHead) {
		exit(-1);
	}
	else {
		ListNode* tail = pHead->_prev;
		pHead->_prev = tail->_prev;
		tail->_prev->_next = pHead;//β�ڵ��ǰһ���ڵ��nextָ��ͷ
		free(tail);
		tail = NULL;
	}
}
// ˫������ͷ��
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
// ˫������ͷɾ
void ListPopFront(ListNode* pHead) 
{
	ListNode* first = pHead->_next;
	pHead->_next = first->_next;
	first->_next->_prev = pHead;//ͷ�ڵ����һ���ڵ��prevָ���ڱ��ڵ�
	free(first);
	first = NULL;
}
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode* Node1 = pos->_prev;//pos��ǰһ���ڵ�
	ListNode* Node2 = pos->_next;//pos�ĺ�һ���ڵ�
	Node1->_next = pos->_next;
	Node2->_prev = pos->_prev;
	free(pos);
	pos = NULL;
}