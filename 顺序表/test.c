#include"Seqlist.h"
void SeqListest1()
{
	SeqList s;
	SeqListInit(&s);
	printf("尾插\n");
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);
	printf("头插\n");
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);
	SeqListPrint(&s);
	printf("按pos（2）位置插\n");
	SeqListInsert(&s, 2, 6);
	SeqListPrint(&s);
	printf("按pos（3）位置删\n");
	SeqListErase(&s, 3);
	SeqListPrint(&s);
	printf("尾删\n");
	SeqListPopBack(&s);
	SeqListPrint(&s);
	printf("头删\n");
	SeqListPopFront(&s);
	SeqListPrint(&s);
	printf("找到了，这个位置在%d \n", SeqListFind(&s, 6));
	SeqListDestory(&s);//销毁
}
int main()
{
	SeqListest1();
	return 0;
}