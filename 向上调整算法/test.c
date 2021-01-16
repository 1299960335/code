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