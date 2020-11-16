#include<stdio.h>
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	for (int i = 31; i >=0;i--) {
		printf("%d", ((n >> i) & 1));
	}
	printf("\n");
	printf("偶数位：");
	for (int i = 31; i >= 0; i-=2) {
		printf("%d", ((n >> i) & 1));
	}
	printf("\n");
	printf("奇数位：");
	for (int j = 30; j >= 0; j -=2) {
		printf("%d", ((n >> j) & 1));
	}
}