#include"Seqlist.h"
void SeqListest1()
{
	SeqList s;
	SeqListInit(&s);
	printf("β��\n");
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);
	printf("ͷ��\n");
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);
	SeqListPrint(&s);
	printf("��pos��2��λ�ò�\n");
	SeqListInsert(&s, 2, 6);
	SeqListPrint(&s);
	printf("��pos��3��λ��ɾ\n");
	SeqListErase(&s, 3);
	SeqListPrint(&s);
	printf("βɾ\n");
	SeqListPopBack(&s);
	SeqListPrint(&s);
	printf("ͷɾ\n");
	SeqListPopFront(&s);
	SeqListPrint(&s);
	printf("�ҵ��ˣ����λ����%d \n", SeqListFind(&s, 6));
	SeqListDestory(&s);//����
}
int main()
{
	SeqListest1();
	return 0;
}