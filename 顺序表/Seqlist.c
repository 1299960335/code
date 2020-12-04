#include"Seqlist.h"
void CheckCapacity(SeqList* ps)//����
{
	assert(ps);
	if (ps->size >= ps->capacity) {
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
	}
	if (ps->a == NULL) {
		printf("����ʧ��");
		exit(-1);
	}
}
void SeqListInit(SeqList* ps)//�����ʼ��
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL) {
		printf("�����ڴ�ʧ��");
		exit(-1);
	}
	ps->capacity = 4;
	ps->size = 0;
}
void SeqListDestory(SeqList* ps)//��������
{
	assert(ps);
	free(ps->a);
	ps = NULL;
	printf("˳���������\n");
}

void SeqListPrint(SeqList* ps)//�����ӡ
{
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)//˳���β��
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)//˳���ͷ��
{
	assert(ps);
	CheckCapacity(ps);
	int a = ps->size;
	while (a >= 0) {//�����������ƣ��ճ���һ��λ��
		ps->a[a + 1] = ps->a[a];
		a--;
	}
	ps->a[0] = x;//��Ŀ��ֵ�����ڵ�һ��λ��
	ps->size++;
}
void SeqListPopFront(SeqList* ps)//˳���ͷɾ
{
	assert(ps);
	for (int i = 0; i < ps->size - 1; i++) {//����������
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)//˳���βɾ
{
	assert(ps);
	ps->size--;
}

// ˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	int a = -1;
	for (int i = 0; i < ps->size; i++) {
		 a = ps->a[i];
		if (a == x) {
			return i;
			break;
		}
	}
	return a;
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	if (pos <= 0) {
		printf("posֵ����");
	}
	int a = 0;
	int b = 0;
	a = ps->size;
	b = ps->size - pos + 1;//ѭ�������ж�
	while (b >= 0) {       //��posλ�ú��Ԫ�ؽ�������
		ps->a[a + 1] = ps->a[a];
		b--;
		a--;
	}
	ps->a[pos - 1] = x;//�ڹ̶�λ�ò���
	ps->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	if (pos <= 0) {
		printf("posֵ����");
	}
	int a = 0;
	a = pos - 1;//�ҵ�posλ�õ��±�
	for (; a < ps->size; a++) {
		ps->a[a] = ps->a[a + 1];//��������
	}
	ps->size--;
}