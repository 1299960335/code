
void Swap(int* a, int* b) {
	int j = 0;
	j = *a;
	*a = *b;
	*b = j;
}
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n) {
		if (child < n && a[child + 1] < a[child]) {//选出小的孩子
			child++;
		}
		if (a[child] < a[parent]) {//如果小于父亲，则进行交换
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
