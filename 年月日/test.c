#include<stdio.h>
void Run_Nian(int a, int arr[])
{
	for (int i = 0; i < 12; i++) {
		if (a <= arr[i]) {
			printf("%d��%d��", i+1, a);
			break;
		}
		a = a - arr[i];
	}
}
void Nian(int a, int arr[])
{
	for (int i = 0; i < 12; i++) {
		a = a - arr[i];
		if (a <= arr[i]) {
			printf("%d��%d��", i+1, a);
			break;
		}
	}
}
int main()
{
	int a = 0;
	int quit = 0;
	int b = 0;
	int arr1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int arr2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	while (!quit) {
		printf("�Ƿ������꣨1.��   2.��\n");
		scanf_s("%d", &a);
		printf("������һ����\n");
		scanf_s("%d", &b);
		while (!quit) {
			if (b < 1 || b>366) {
				printf("������������������");
			}
			else {
				quit = 1;
			}
		}
		if (a == 1) {
			Run_Nian(b, arr2);
			quit = 1;
		}
		else if (a == 2) {
			Nian(b, arr1);
			quit = 1;
		}
		else {
			printf("������������������");
		}
	}
	return 0;
}