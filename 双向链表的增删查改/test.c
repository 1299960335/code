#include"List.h"
void test()
{
	ListNode* p= ListCreate();
	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListPrint(p);
	ListPopBack(p);
	ListPopBack(p);
	ListPopBack(p);
	ListPopBack(p);
	ListPrint(p);
	ListPushFront(p, 1);
	ListPushFront(p, 2);
	ListPushFront(p, 3);
	ListPushFront(p, 4);
	ListPrint(p);
	ListPopFront(p);
	ListPopFront(p);
	ListPopFront(p);
	ListPopFront(p);
	ListPrint(p);

}
void test2()
{
	ListNode* p = ListCreate();
	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListNode* pos = ListFind(p, 3);
	ListInsert(pos, 5);
	ListPrint(p);
	ListErase(pos);
	ListPrint(p);
	ListDestory(p);
	ListPrint(p);
}
int main()
{
	test();
	return 0;
}