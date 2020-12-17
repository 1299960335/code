#include"SList.h"
void test()
{
	SListNode* p = NULL;
	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);
	SListPrint(p);
	//SListPushFront(&p, 5);
	//SListPushFront(&p, 6);
	//SListPushFront(&p, 7);
	SListNode*s= SListFind(p, 3);
	if (s != NULL) {
		printf("%d\n", s->data);
	}
	//SListPopBack(&p);
	SListPrint(p);
 
 
}
 
 
int main()
{
	test();
	return 0;
}