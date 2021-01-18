#include"Heap.h"
void Swap(int* a, int* b) {//交换函数
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustDown(int *a,int n,int root) {//向下调整算法
	assert(a);
	int preant = root;
	int child = preant * 2 + 1;
	while (child < n) {
		if (child + 1 < n && a[child + 1] < a[child])//找出左右孩子小的那一个
		{
			++child;
		}
		if (a[child] < a[preant]) {//如果孩子小于父亲，则进行交换
			Swap(&a[child], &a[preant]);
			preant = child;
			child = preant * 2 + 1;
		}
		else {
			break;
		}
	}
}
void AdjustUp(int* a, int n)//向上调整算法
{
	assert(a);
	int child = n - 1;
	int preant = (child - 1) / 2;
	while (preant > 0) {
		if (a[child] < a[preant]) {
			Swap(&a[child], &a[preant]);
			child = preant;
			preant = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	assert(a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(hp->_a, a, sizeof(HPDataType) * n);//拷贝给定的数组
	hp->_capacity = n;
	hp->_size = n;
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {//叶子节点不需要进行调整
		AdjustDown(hp->_a, n, i);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity) {
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//将堆顶的数据与最后的数据进行交换
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 1;
}
// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	assert(a);
	int size = n-1;
	for (int i = (n - 1 - 1) / 2; i >= 0 ; i--) {
		AdjustDown(a, n, i);
	}
	while (size > 0) {
		Swap(&a[0], &a[size]);
		AdjustDown(a, size, 0);
		size--;
	}
}
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	Heap hp;
	HeapCreate(&hp, a, k);    //建立一个K容量的小堆
	for (int i = k; i < n; i++) {
		if (a[i] > (&hp)->_a[0]) {//如果数组中有大于堆顶的数，将其入堆
			Swap(&a[i], &(&hp)->_a[0]);
			AdjustDown((&hp)->_a, k, 0);
		}
	 }
	for (int j = 0; j < k; j++) {
		printf("%d ", (&hp)->_a[j]);
	}
	printf("\n");
}