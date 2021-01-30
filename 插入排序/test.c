// 插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++) {
		int end = i;
		int temp = a[end + 1];
		while (end >= 0) {
			if (temp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = temp;
	}
}
