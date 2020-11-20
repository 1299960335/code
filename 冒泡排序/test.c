#include<stdio.h>
int Bubbling(int arr[]) {
	int a = 0;
	int b = 0;
	int c;
	for (a = 1; a < 7; a++) {
		for (b = 0; b < 7 - a; b++) {
			if (arr[b] > arr[b + 1]) {
				c = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = c;
			}
		}
	}
	for (int d = 0; d < 7; d++) {
		printf("%d ", arr[d]);
	}
	return 0;
}
int main()
{
	int arr[7] = { 10,30,54,28,90,35,61 };
	Bubbling(arr);
	return 0;
}