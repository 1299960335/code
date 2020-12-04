#include"Seqlist.h"
void CheckCapacity(SeqList* ps)//增容
{
	assert(ps);
	if (ps->size >= ps->capacity) {
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
	}
	if (ps->a == NULL) {
		printf("扩容失败");
		exit(-1);
	}
}
void SeqListInit(SeqList* ps)//链表初始化
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL) {
		printf("申请内存失败");
		exit(-1);
	}
	ps->capacity = 4;
	ps->size = 0;
}
void SeqListDestory(SeqList* ps)//链表销毁
{
	assert(ps);
	free(ps->a);
	ps = NULL;
	printf("顺序表已销毁\n");
}

void SeqListPrint(SeqList* ps)//链表打印
{
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)//顺序表尾插
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)//顺序表头插
{
	assert(ps);
	CheckCapacity(ps);
	int a = ps->size;
	while (a >= 0) {//将内容向右移，空出第一个位置
		ps->a[a + 1] = ps->a[a];
		a--;
	}
	ps->a[0] = x;//将目标值放置在第一个位置
	ps->size++;
}
void SeqListPopFront(SeqList* ps)//顺序表头删
{
	assert(ps);
	for (int i = 0; i < ps->size - 1; i++) {//将内容左移
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)//顺序表尾删
{
	assert(ps);
	ps->size--;
}

// 顺序表查找
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
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	if (pos <= 0) {
		printf("pos值有误");
	}
	int a = 0;
	int b = 0;
	a = ps->size;
	b = ps->size - pos + 1;//循环次数判定
	while (b >= 0) {       //将pos位置后的元素进行右移
		ps->a[a + 1] = ps->a[a];
		b--;
		a--;
	}
	ps->a[pos - 1] = x;//在固定位置插入
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	if (pos <= 0) {
		printf("pos值有误");
	}
	int a = 0;
	a = pos - 1;//找到pos位置的下标
	for (; a < ps->size; a++) {
		ps->a[a] = ps->a[a + 1];//将其左移
	}
	ps->size--;
}