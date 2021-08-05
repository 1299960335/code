int size(long long n)
{
	int max = 1;
	int num = 1;
	for (int i=1; i < n; i++) {
		if (max > i) {
			i = max;
		}
		else {
			max += i;
			num++;
		}
	}
	return num;
}