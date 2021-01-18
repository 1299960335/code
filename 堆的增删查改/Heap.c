#include"Heap.h"
void Swap(int* a, int* b) {//��������
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustDown(int *a,int n,int root) {//���µ����㷨
	assert(a);
	int preant = root;
	int child = preant * 2 + 1;
	while (child < n) {
		if (child + 1 < n && a[child + 1] < a[child])//�ҳ����Һ���С����һ��
		{
			++child;
		}
		if (a[child] < a[preant]) {//�������С�ڸ��ף�����н���
			Swap(&a[child], &a[preant]);
			preant = child;
			child = preant * 2 + 1;
		}
		else {
			break;
		}
	}
}
void AdjustUp(int* a, int n)//���ϵ����㷨
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
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	assert(a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(hp->_a, a, sizeof(HPDataType) * n);//��������������
	hp->_capacity = n;
	hp->_size = n;
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {//Ҷ�ӽڵ㲻��Ҫ���е���
		AdjustDown(hp->_a, n, i);
	}
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// �ѵĲ���
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
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//���Ѷ����������������ݽ��н���
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 1;
}
// ��������ж�����
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
	HeapCreate(&hp, a, k);    //����һ��K������С��
	for (int i = k; i < n; i++) {
		if (a[i] > (&hp)->_a[0]) {//����������д��ڶѶ��������������
			Swap(&a[i], &(&hp)->_a[0]);
			AdjustDown((&hp)->_a, k, 0);
		}
	 }
	for (int j = 0; j < k; j++) {
		printf("%d ", (&hp)->_a[j]);
	}
	printf("\n");
}