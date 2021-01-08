
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
		if (child < n && a[child + 1] < a[child]) {//ѡ��С�ĺ���
			child++;
		}
		if (a[child] < a[parent]) {//���С�ڸ��ף�����н���
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
