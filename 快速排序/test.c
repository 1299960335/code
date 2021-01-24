#include<stdio.h>
#include<assert.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int GetMidIndex(int *a,int begin,int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid]) {
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else {
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}
int PartSort3(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[end], &a[midIndex]);
	assert(a);
	int cur = begin;
	int prev = begin - 1;
	int key = a[end];
	while (cur<=end) {
		if (a[cur] < key && ++prev != cur) {
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	prev++;
	Swap(&a[prev], &a[end]);
}
void QuitSort(int *a,int left ,int right)
{
	assert(a);
	if (left >= right)
		return;
	int div = PartSort3(a, left, right);
	QuitSort(a, left, div - 1);
	QuitSort(a, div + 1, right);
}
int main()
{
	int a[] = { 1, 2, 5, 9, 7, 8, 6, 3, 4, 0 };
	QuitSort(a, 0, 9);
	for(int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}