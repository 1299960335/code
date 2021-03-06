void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[gap + end];
			while (end >= 0)
				if (tmp < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			a[end + gap] = tmp;
		}
	}
}
